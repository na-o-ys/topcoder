use std::io;
use std::fmt;
use std::cmp;
use std::time::{SystemTime};
use std::ops::{Index, IndexMut};

const N: usize = 50;

fn main() {
    let mut table = Table::read();
    let mut vanished_table = table.clone();
    vanished_table.vanish();

    let mut rng = Rng::from_seed(urand());
    let mut sa = Anealing::new(SystemTime::now(), 9500);

    let mut current_score: u32 = 0;
    while sa.remainig() > 0.0 {
        let r = rng.next_idx(N);

        let mut row = *table.get_row(r);
        randomize(&mut row, &mut rng);

        let v_row_crr = *vanished_table.get_row(r);
        let mut v_row_nxt = row.clone();
        vanish_row(&mut v_row_nxt);
        vanished_table.set_row(r, v_row_nxt);
        let next_score = vanished_table.score();

        // p(current_score);
        if sa.transition(current_score as i32, next_score as i32) {
            table.set_row(r, row);
            current_score = next_score;
        } else {
            vanished_table.set_row(r, v_row_crr);
        }
    }
    // table.show();
    p(vanished_table.score());
 
    // p(Table::rand())
}

fn randomize(row: &mut Row, rng: &mut Rng) {
    for c in 1..N {
        if row[c] == 'o' || row[c] == 'x' { continue; }
        let sym = ['.', '.', '.', '.', '.', '.', '.', '.', '.', '+'];
        row[c] = sym[rng.next_idx(10)];
    }
}

#[allow(dead_code)]
struct Anealing {
    start_time: SystemTime,
    limit_ms:   f32,
    p1:         f32,
    p2:         f32,
    rng:        Rng
}

impl Anealing {
    fn new(start_time: SystemTime, limit_ms: u32) -> Anealing {
        let rng = Rng::from_seed(urand());
        const FACTOR: f32 = 4.8;
        let p1 = FACTOR;
        let p2 = N as f32 / 2.0;
        Anealing { start_time: start_time, limit_ms: limit_ms as f32, p1: p1, p2: p2, rng: rng }
    }

    fn transition(&mut self, current_score: i32, next_score: i32) -> bool {
        if current_score < next_score { return true; }
        let probability = ((next_score - current_score) as f32 / self.temperture()).exp();
        self.rng.next_f() < probability
    }

    fn temperture(&self) -> f32 {
        self.p2 * (self.remainig() * self.p1).exp() / self.p1.exp()
    }

    fn remainig(&self) -> f32 {
        let elapsed = self.start_time.elapsed().unwrap();
        let elapsed_ms = (elapsed.as_secs() * 1000) as f32 + elapsed.subsec_nanos() as f32 / 1000000.0;
        (self.limit_ms - elapsed_ms) / self.limit_ms
    }
}

#[derive(Copy)]
struct Row {
    row: [char; N]
}

impl Row {
    fn new() -> Row {
        Row { row: ['.'; N] }
    }
}

impl Clone for Row {
    fn clone(&self) -> Row {
        let mut row = ['.'; N];
        for c in 0..N {
            row[c] = self.row[c]
        }
        Row { row: row }
    }
}

impl Index<usize> for Row {
    type Output = char;
    fn index(&self, id: usize) -> &char {
        &self.row[id]
    }
}

impl IndexMut<usize> for Row {
    fn index_mut<'a>(&'a mut self, id: usize) -> &mut char {
        &mut self.row[id]
    }
}

#[derive(Copy)]
struct Table {
    rows: [Row; N]
}

impl Clone for Table {
    fn clone(&self) -> Table {
        let mut rows = [Row::new(); N];
        for r in 0..N {
            rows[r] = self.rows[r].clone()
        }
        Table { rows: rows }
    }
}

impl Table {
    fn new(rows: Vec<String>) -> Table {
        let mut table_rows = [Row::new(); N];
        for (i, row) in rows.iter().enumerate() {
            for (j, c) in row.as_bytes().iter().enumerate() {
                table_rows[j][N - 1 - i] = *c as char;
            }
        }
        Table { rows: table_rows }
    }

    fn read() -> Table {
        let rows = (0..N).map(|_| read_line()).collect::<Vec<_>>();
        Table::new(rows)
    }

    // Debug
    #[allow(dead_code)]
    fn rand() -> Table {
        let val = ['.', '.', 'o', 'x'];
        let mut rng = Rng::from_seed(urand());
        let mut table = Table { rows: [Row::new(); N] };
        for r in 0..N {
            for c in 0..N {
                table.set(r, c, val[(rng.next() % 4) as usize]);
            }
        }
        table
    }

    fn show(&self) {
        for r in 0..N {
            for c in 0..N {
                print!("{}", self.rows[c][N - 1 - r]);
            }
            println!("");
        }
    }

    fn get(&self, r: usize, c: usize) -> char {
        self.rows[r][c]
    }

    fn get_row(&self, r: usize) -> &Row {
        &self.rows[r]
    }

    fn set(&mut self, r: usize, c: usize, v: char) {
        self.rows[r][c] = v;
    }

    fn set_row(&mut self, r: usize, row: Row) {
        self.rows[r] = row
    }

    fn vanish(&mut self) {
        for r in 0..N {
            vanish_row(&mut self.rows[r])
        }
    }

    fn score(&self) -> u32 {
        const SYM: [char; 2] = ['o', 'x'];
        fn score_rec(table: &Table, r: usize, c: usize, s: usize, visited: &mut [[[bool; N]; N]; 2]) -> u32 {
            if r >= N || c >= N ||
                visited[s][r][c] || table.get(r, c) != SYM[s] {
                return 0;
            }
            visited[s][r][c] = true;
            1 + score_rec(table, r, c + 1, s, visited) +
                score_rec(table, r + 1, c, s, visited) +
                score_rec(table, r, if c == 0 { 0 } else { c - 1 }, s, visited) +
                score_rec(table, if r == 0 { 0 } else { r - 1 }, c, s, visited)
        };
        let mut visited = [[[false; N]; N]; 2];
        let mut score_0 = 0;
        let mut score_1 = 0;
        for r in 0..N {
            for c in 0..N {
                score_0 = cmp::max(score_0, score_rec(self, r, c, 0, &mut visited));
                score_1 = cmp::max(score_1, score_rec(self, r, c, 1, &mut visited));
            }
        }
        score_0 + score_1
    }
}

fn vanish_row(row: &mut Row) {
    let mut slide: usize = 0;
    for c in 0..N {
        while c + slide < N && row[c + slide] == '.' { slide += 1 };
        let v = if c + slide < N { row[c + slide] } else { 'D' };
        row[c] = match v {
            '-' => {
                if slide == 0 {
                    '-'
                } else {
                    slide -= 1;
                    'D'
                }
            }
            _   => v,
        }
    }
}

impl fmt::Display for Table {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        for r in 0..N {
            for c in 0..N {
                write!(f, "{}", self.rows[r][c]).unwrap();
            }
            writeln!(f, "").unwrap();
        }
        write!(f, "")
    }
}

#[allow(dead_code)]
fn urand() -> [u32; 4] {
    use std::io::Read;
    let mut buf = [0; 16];
    let mut f = std::fs::File::open("/dev/urandom").unwrap();
    f.read(&mut buf).unwrap();
    let mut rnd = [0; 4];
    for j in 0..4 {
        for i in 0..4 {
            rnd[j] <<= 8;
            rnd[j] ^= buf[i] as u32;
        }
    }
    rnd
}

struct Rng {
    x: u32,
    y: u32,
    z: u32,
    w: u32,
}

#[allow(dead_code)]
impl Rng {
    fn new() -> Rng {
        return Rng {
            x: 0x193a6754,
            y: 0xa8a7d469,
            z: 0x97830e05,
            w: 0x113ba7bb,
        }
    }

    fn from_seed(seed: [u32; 4]) -> Rng {
        return Rng {
            x: seed[0],
            y: seed[1],
            z: seed[2],
            w: seed[3]
        }
    }

    fn next(&mut self) -> u32 {
        let t = self.x ^ (self.x << 11);
        self.x = self.y;
        self.y = self.z;
        self.z = self.w;
        self.w = (self.w ^ (self.w >> 19)) ^ (t ^ (t >> 8));
        return self.w
    }

    fn next_f(&mut self) -> f32 {
        self.next() as f32 / std::u32::MAX as f32
    }

    fn next_idx(&mut self, n: usize) -> usize {
        (self.next() % n as u32) as usize
    }
}

#[allow(dead_code)]
fn p<T: std::fmt::Display>(v: T) {
    println!("{}", v)
}

#[allow(dead_code)]
fn read_int() -> i32 {
    read_line().parse().unwrap()
}

#[allow(dead_code)]
fn read_line() -> String {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    line.trim().to_string()
}

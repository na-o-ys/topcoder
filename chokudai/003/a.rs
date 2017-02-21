use std::io;
use std::fmt;
use std::cmp;

const N: usize = 10;

fn main() {
    let mut table = Table::read();
    p(&table);
    let mut row = *table.get_row(0);
    row[0] = 'I';
    for i in 0..N {
        print!("{}", row[i]);
    }
    println!("");
    table.set_row(1, row);
    p(&table);
    // table.set(1, 1, '+');
    table.vanish();
    p(table.score());
}

struct Table {
    rows: [[char; N]; N]
}

impl Table {
    fn new(rows: Vec<String>) -> Table {
        let mut table_rows = [['.'; N]; N];
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
    fn rand() -> Table {
        let val = ['.', '.', 'o', 'x'];
        let mut rng = Rng::from_seed(urand());
        let mut table = Table { rows: [['.'; N]; N] };
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
                print!("{}", self.rows[r][c]);
            }
            println!("");
        }
    }

    fn get(&self, r: usize, c: usize) -> char {
        self.rows[r][c]
    }

    fn get_row(&self, r: usize) -> &[char; N] {
        &self.rows[r]
    }

    fn set(&mut self, r: usize, c: usize, v: char) {
        self.rows[r][c] = v;
    }

    fn set_row(&mut self, r: usize, row: [char; N]) {
        self.rows[r] = row
    }

    fn vanish(&mut self) {
        for r in 0..N {
            vanish_row(&mut self.rows[r])
        }
    }

    fn score(&self) -> u32 {
        const sym: [char; 2] = ['o', 'x'];
        fn score_rec(table: &Table, r: usize, c: usize, s: usize, visited: &mut [[[bool; N]; N]; 2]) -> u32 {
            if r >= N || c >= N ||
                visited[s][r][c] || table.get(r, c) != sym[s] {
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

fn vanish_row(row: &mut [char; N]) {
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
}

fn p<T: std::fmt::Display>(v: T) {
    println!("{}", v)
}

fn read_int() -> i32 {
    read_line().parse().unwrap()
}

fn read_line() -> String {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    line.trim().to_string()
}

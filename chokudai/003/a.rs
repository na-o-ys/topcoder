use std::io;
use std::fmt;

const N: usize = 50;

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

    fn set(&mut self, r: usize, c: usize, v: char) {
        self.rows[r][c] = v;
    }

    fn vanish(&mut self) {
        for r in 0..N {
            vanish_row(&mut self.rows[r])
        }
    }
}

fn vanish_row(row: &mut [char; N]) {
    let mut geta: usize = 0;
    for c in 0..N {
        let v = if c + geta < N { row[c + geta] } else { 'D' };
        if row[c] == '-' { continue; }
        row[c] = match v {
            'o' | 'x' | '+' => v,
            '.'             => {
                while c + geta < N && row[c + geta] == '.' {
                    geta += 1;
                }
                if c + geta < N {
                    row[c + geta]
                } else {
                    'D'
                }
            },
            _         => 'D'
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

fn main() {
    let mut table = Table::read();
    table.vanish();
    p(table);
    // table.show();
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

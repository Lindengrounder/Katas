use std::io::{self, Write};

const WIDTH: usize = 10;

#[derive(Copy, Clone, PartialEq)]
enum Cell {
    Empty,
    Filled,
}

type Shape = [[Cell; 4]; 4];

struct Tetromino {
    shape: Shape,
}

impl Tetromino {
    fn new(shape: Shape) -> Tetromino {
        Tetromino { shape }
    }
}

fn draw_shape(shape: &Shape) {
    for row in shape.iter() {
        for cell in row.iter() {
            match cell {
                Cell::Filled => print!("██"),
                Cell::Empty => print!("  "),
            }
        }
        println!();
    }
}

fn main() {
    let shapes = [
        [
            [Cell::Filled, Cell::Filled, Cell::Filled, Cell::Filled],
            [Cell::Empty, Cell::Empty, Cell::Empty, Cell::Empty],
            [Cell::Empty, Cell::Empty, Cell::Empty, Cell::Empty],
            [Cell::Empty, Cell::Empty, Cell::Empty, Cell::Empty],
        ],
        [
            [Cell::Filled, Cell::Filled, Cell::Empty, Cell::Empty],
            [Cell::Filled, Cell::Filled, Cell::Empty, Cell::Empty],
            [Cell::Empty, Cell::Empty, Cell::Empty, Cell::Empty],
            [Cell::Empty, Cell::Empty, Cell::Empty, Cell::Empty],
        ],
        [
            [Cell::Filled, Cell::Filled, Cell::Filled, Cell::Empty],
            [Cell::Empty, Cell::Filled, Cell::Empty, Cell::Empty],
            [Cell::Empty, Cell::Empty, Cell::Empty, Cell::Empty],
            [Cell::Empty, Cell::Empty, Cell::Empty, Cell::Empty],
        ],
        [
            [Cell::Empty, Cell::Filled, Cell::Filled, Cell::Empty],
            [Cell::Filled, Cell::Filled, Cell::Empty, Cell::Empty],
            [Cell::Empty, Cell::Empty, Cell::Empty, Cell::Empty],
            [Cell::Empty, Cell::Empty, Cell::Empty, Cell::Empty],
        ],
        [
            [Cell::Filled, Cell::Filled, Cell::Empty, Cell::Empty],
            [Cell::Empty, Cell::Filled, Cell::Filled, Cell::Empty],
            [Cell::Empty, Cell::Empty, Cell::Empty, Cell::Empty],
            [Cell::Empty, Cell::Empty, Cell::Empty, Cell::Empty],
        ],
        [
            [Cell::Filled, Cell::Empty, Cell::Empty, Cell::Empty],
            [Cell::Filled, Cell::Filled, Cell::Filled, Cell::Empty],
            [Cell::Empty, Cell::Empty, Cell::Empty, Cell::Empty],
            [Cell::Empty, Cell::Empty, Cell::Empty, Cell::Empty],
        ],
        [
            [Cell::Empty, Cell::Empty, Cell::Filled, Cell::Empty],
            [Cell::Filled, Cell::Filled, Cell::Filled, Cell::Empty],
            [Cell::Empty, Cell::Empty, Cell::Empty, Cell::Empty],
            [Cell::Empty, Cell::Empty, Cell::Empty, Cell::Empty],
        ],
    ];

    loop {
        println!("\nВыберите фигуру тетромино:");
        for (i, _) in shapes.iter().enumerate() {
            println!("{}. Фигура {}", i + 1, i + 1);
        }
        println!("0. Выход");

        print!("Введите номер фигуры: ");
        io::stdout().flush().unwrap();

        let mut input = String::new();
        io::stdin().read_line(&mut input).expect("Ошибка чтения строки");

        let choice: u32 = match input.trim().parse() {
            Ok(num) => num,
            Err(_) => {
                println!("Неверный ввод. Пожалуйста, введите число.");
                continue;
            }
        };

        match choice {
            0 => break,
            1..=7 => draw_shape(&shapes[(choice - 1) as usize]),
            _ => println!("Неверный номер фигуры. Пожалуйста, выберите номер от 1 до 7."),
        }
    }

    println!("До свидания!");
}

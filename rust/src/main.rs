struct Punto{
    x: f64,
    y: f64,
}

impl Punto {
    // Constructor (convención: new)
    fn new(x: f64, y: f64) -> Punto {
        Punto { x, y }
    }

    // Método (self = this)
    fn distancia(&self, otro: &Punto) -> f64 {
        ((self.x - otro.x).powi(2) + (self.y - otro.y).powi(2)).sqrt()
    }
}

enum Resultado {
    Ok(i32),
    Error(String),
}

fn dividir(a: i32, b: i32) -> Resultado {
    if b == 0 {
        Resultado::Error("División por cero".to_string())
    } else {
        Resultado::Ok(a / b)
    }
}

// // Pattern matching (como switch pero mucho más potente)
// match dividir(10, 2) {
//     Resultado::Ok(valor) => println!("Resultado: {}", valor),
//     Resultado::Error(msg) => println!("Error: {}", msg),
// }

trait Animal {
    fn sonido(&self) -> &str;
    fn descripcion(&self) -> String {
        format!("Hago {}", self.sonido())  // implementación por defecto
    }
}

struct Perro;
impl Animal for Perro {
    fn sonido(&self) -> &str { "guau" }
}

fn main()
{
    // Primitivos
    let x: i32 = 42;
    let y: f64 = 3.14;
    let b: bool = true;
    let c: char = 'a';
    
    // Inmutabilidad por defecto (¡al revés que Java!)
    let a = 5;        // inmutable
    let mut b = 5;    // mutable
    b = 6;            // OK
    // a = 6;         // ERROR
    
    // Tuplas y arrays
    let tup: (i32, f64) = (42, 3.14);
    let arr: [i32; 3] = [1, 2, 3];
    
    // String vs &str (importante)
    let s: &str = "literal";         // en stack, tamaño fijo
    let s: String = String::from("heap"); // en heap, crecer/shrink
}

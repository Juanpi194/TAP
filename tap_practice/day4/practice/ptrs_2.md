&   →  "te presto el objeto, lo devuelvo intacto"
&&  →  "te cedo el objeto, puedes vaciarlo"

-----------------------------------------------------------
std::string a = "hola";
std::string b = std::move(a);

// a sigue existiendo, pero su contenido fue robado
// a == ""  (válido pero vacío)
// b == "hola"

En resumen:
Leer sin modificar ------------------- const &
Modificar el original ---------------- &
Robar los recursos ------------------- &&
Trabajar con copia independiente ----- por valor
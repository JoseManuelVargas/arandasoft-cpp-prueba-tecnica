CREATE TABLE ArbolBinario (
  id BIGINT NOT NULL PRIMARY KEY,
  creacion TEXT,
  nombre TEXT
);
CREATE TABLE Nodo (
  arbol_id BIGINT NOT NULL, 
  valor INTEGER,
  FOREIGN KEY(arbol_id) REFERENCES ArbolBinario(id)
);
CREATE INDEX nodo_arbol_id_index ON Nodo(arbol_id);

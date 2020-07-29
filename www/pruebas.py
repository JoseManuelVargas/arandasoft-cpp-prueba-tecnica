import unittest
import requests


class Pruebas(unittest.TestCase):
    def setUp(self):
        self.url = "http://localhost:5000/arbolbinario"

    def test_error_creacion(self):
        datos = {"nombre": "Arbol1 Py", "erroneo": [5, 3, 8, 4, 12, 3]}
        respuesta = requests.post(self.url + "/crear", json=datos)
        self.assertEqual(respuesta.status_code, 400)
        r_json = respuesta.json()
        self.assertTrue("error" in r_json)
        self.assertTrue("mensaje" in r_json)
        datos = {"nombre": "Arbol1", "valores": [5, 3, 8, 4, 12, 3]}
        respuesta = requests.post(self.url + "/crearfalso", json=datos)
        self.assertEqual(respuesta.status_code, 404)
    
    def test_creacion_arbol(self):
        datos = {"nombre": "Arbol1 Py", "valores": [5, 3, 8, 4, 12, 3]}
        respuesta = requests.post(self.url + "/crear", json=datos)
        self.assertEqual(respuesta.status_code, 200)
        r_json = respuesta.json()
        self.assertTrue("error" not in r_json)
        self.assertTrue("nombre" in r_json)
        self.assertEqual(r_json["nombre"], datos["nombre"])
        self.assertTrue("id" in r_json)
        self.assertGreater(r_json["id"], 0)

    def test_ancestro(self):
        datos = {"nombre": "Arbol2 Py", "valores": [5, 3, 8, 4, 12, 3]}
        respuesta = requests.post(self.url + "/crear", json=datos)
        self.assertEqual(respuesta.status_code, 200)
        r_json = respuesta.json()
        self.assertTrue("error" not in r_json)
        self.assertTrue("nombre" in r_json)
        self.assertEqual(r_json["nombre"], datos["nombre"])
        self.assertTrue("id" in r_json)
        self.assertGreater(r_json["id"], 0)
        id_arbol = r_json["id"]
        datos = {"id": id_arbol, "nodo1": 3, "nodo2": 5}
        respuesta = requests.post(self.url + "/ancestrocomun", json=datos)
        self.assertEqual(respuesta.status_code, 200)
        r_json = respuesta.json()
        self.assertTrue("error" not in r_json)
        self.assertTrue("ancestro" in r_json)
        self.assertGreater(r_json["ancestro"], 0)


if __name__ == "__main__":
    unittest.main()


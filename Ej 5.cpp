#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Alumno {
private:
    string nombre;
    int edad;
    double nota1;
    double nota2;
    double nota3;
    string estado;

    void actualizarEstado() {
        if (estaAprobado()) {
            estado = "Aprobado";
        } else {
            estado = "Desaprobado";
        }
    }

public:
    Alumno(string nombre, int edad, double nota1, double nota2, double nota3)
    : nombre(nombre), edad(edad), nota1(nota1), nota2(nota2), nota3(nota3), estado("") {
        actualizarEstado();
    }

    string getNombre() const { return nombre; }
    int getEdad() const { return edad; }
    double getNota1() const { return nota1; }
    double getNota2() const { return nota2; }
    double getNota3() const { return nota3; }
    string getEstado() const { return estado; }

    double calcularPromedio() const {
        return (nota1 + nota2 + nota3) / 3;
    }

    bool estaAprobado() const {
        return calcularPromedio() >= 7;
    }

    double notaMaxima() const {
        double maxima = nota1;
        if (nota2 > maxima) {
            maxima = nota2;
        }
        if (nota3 > maxima) {
            maxima = nota3;
        }
        return maxima;
    }

    double notaMinima() const {
        double minima = nota1;
        if (nota2 < minima) {
            minima = nota2;
        }
        if (nota3 < minima) {
            minima = nota3;
        }
        return minima;
    }

    void mostrar() const {
        cout<<"Nombre: "<<nombre<<endl;
        cout<<"Edad: "<<edad<<endl;
        cout<<"Nota 1: "<<nota1<<endl;
        cout<<"Nota 2: "<<nota2<<endl;
        cout<<"Nota 3: "<<nota3<<endl;
        cout<<"Promedio: "<<calcularPromedio()<<endl;
        cout<<"Nota mas alta: "<<notaMaxima()<<endl;
        cout<<"Nota mas baja: "<<notaMinima()<<endl;
        cout<<"Estado: "<<estado<<endl;
    }
};

int buscarAlumno(const vector<Alumno>& alumnos, string nombreBuscado) {
    for (int i = 0; i < alumnos.size(); i++) {
        if (alumnos[i].getNombre() == nombreBuscado) {
            return i;
        }
    }
    return 0;
}

double calcularPromedioGeneral(const vector<Alumno>& alumnos) {
    if (alumnos.size() == 0) {
        return 0;
    }
    double suma = 0;
    for (int i = 0; i < alumnos.size(); i++) {
        suma = suma + alumnos[i].calcularPromedio();
    }
    return suma / alumnos.size();
}

int main() {
    vector<Alumno> alumnos;
    string nombre;
    int edad;
    double nota1, nota2, nota3;
    int numAlumnos;

    cout<<"Digite el numero de alumnos: "; cin>>numAlumnos;

    for (int i = 0; i < numAlumnos; i++) {
        cout<<endl<<"Alumno "<<i + 1<<endl;
        cout<<"Digite el nombre del alumno: "; cin>>nombre;
        cout<<"Digite la edad del alumno: "; cin>>edad;
        cout<<"Digite la nota 1 del alumno: "; cin>>nota1;
        cout<<"Digite la nota 2 del alumno: "; cin>>nota2;
        cout<<"Digite la nota 3 del alumno: "; cin>>nota3;
        alumnos.push_back(Alumno(nombre, edad, nota1, nota2, nota3));
    }

    cout<<endl<<"DATOS DE LOS ALUMNOS"<<endl;
    for (int i = 0; i < alumnos.size(); i++) {
        cout<<endl;
        alumnos[i].mostrar();
    }

    cout<<endl<<"RESULTADO DE CADA ALUMNO"<<endl;
    for (int i = 0; i < alumnos.size(); i++) {
        if (alumnos[i].estaAprobado()) {
            cout<<alumnos[i].getNombre()<<": Aprobado"<<endl;
        } else {
            cout<<alumnos[i].getNombre()<<": Desaprobado"<<endl;
        }
    }

    string nombreBuscado;
    cout<<endl<<"BUSQUEDA DE ALUMNO"<<endl;
    cout<<"Digite el nombre del alumno a buscar: "; cin>>nombreBuscado;

    int posicion = buscarAlumno(alumnos, nombreBuscado);
    if (posicion == -1) {
        cout<<"No se encontro ningun alumno con el nombre "<<nombreBuscado<<endl;
    } else {
        cout<<"Alumno encontrado en la posicion "<<posicion<<endl<<endl;
        alumnos[posicion].mostrar();
    }

    cout<<endl<<"PROMEDIO GENERAL DE TODOS LOS ALUMNOS: "<<calcularPromedioGeneral(alumnos)<<endl;

    return 0;
}

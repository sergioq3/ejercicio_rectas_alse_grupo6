#include <iostream>
using namespace std;

float ingresa_e_imprime_r1(float numerador_1, float denominador_1);     			   //PROTOTIPO DE FUNCIONES UTILIZADAS
float ingresa_e_imprime_r2(float numerador_1, float denominador_1);
void halla_interseccion(float m1, float b1, float m2, float b2);
void evalua_pendiente(float m1, float b1, float m2, float b2);

class punto{                                                         				   //CLASE QUE CONTIENE LOS PUNTOS DE LAS RECTAS
protected:                                                         				       //PROTECTED PARA QUE SE PUEDA ACCEDER A ELLA DESDE LA SUBCLASE
	float x;                                                      				       //COORDENADA EN X DEL PUNTO INGRESADO
	float y;                                                      				       //COORDENADA EN Y DEL PUNTO INGRESADO
public:
	punto():x(0), y(0)                                                                 //INICIALIZACION DE LOS PUNTOS
	{}
	void set_punto()                                                                   //METODO PARA ACCEDER A LAS VARIABLES
	{
		float a, b;
		x=a;
		y=b;
	}
	void ingresar_punto(int n)                                     			           //SE INGRESAN LAS COORDENADAS X y Y DEL PUNTO
	{                                                              			           //LA VARIABLE n SE UTILIZA UNICAMENTE PARA DECIR SI ES EL PUNTO 1 O 2
		cout<<endl<<"    Ingrese las coordenadas del "<<"Punto "<< n << endl;
		cout<<"        valor en x: ";                                            
		cin>>x;
		cout<<"        valor en y: ";
		cin>>y;
	}
	void mostrar_punto(int n)                                                         //IMPRIME LAS COORDENADAS INGRESADAS, n CUMPLE LA MISMA FUNCION MENCIONADA
	{
		cout<<endl<<"    La coordenada x ingresada del punto "<<n<<" es: "<< x << endl;
		cout<<      "    La coordenada y ingresada del punto "<<n<<" es: "<< y << endl;
	}
};

class recta:public punto                                                              //SUBCLASE RECTA DE LA CLASE PUNTO
{
public:
	                                                                                  //COMO SABEMOS, LA PENDIENTE TIENE NUMERADOR Y DENOMINADOR YA QUE ES UN COCIENTE
	float num_pendiente(float numerador_2)                                            //FUNCION QUE RETORNA EL NUMERADOR LUEGO DE LA OPERACION
	{
		numerador_2=y-numerador_2;                                                    //OPERACION ENTRE LAS COORDENADAS Y DE CADA UNO DE LOS PUNTOS
		return numerador_2;
	}
	float den_pendiente(float denominador_2)                                          //FUNCION QUE RETORNA EL DENOMINADOR LUEGO DE LA OPERACION
	{
		denominador_2=x-denominador_2;                                                //OPERACION ENTRE LAS COORDENADAS X DE CADA UNO DE LOS PUNTOS
		return denominador_2;
	}
	float corte(float m)                                                              //HALLA EL PUNTO DE CORTE DE LA RECTA, UTILIZANDO LA COORDENADA X y Y
	{
		float b=0;                                                                    //B ES EL PUNTO DE CORTE DE LA RECTA
		b=y-(m*x);
		return b;
	}
};	

recta r1,r2;                                                                          //ALIAS DE CLASE RECTA

int main(void)                                                                       //FUNCION MAIN
{
	float numerador=0;                                                               //VARIABLES DE LOS NUMERADORES, DENOMINADORES, PENDIENTES Y PUNTOS DE CORTE
	float denominador=0;
	float pendiente_r1=0;
	float pendiente_r2=0;
	float corte_r1=0;
	float corte_r2=0;
	
	cout<<endl<<"Puntos recta 1"<<endl; 
	pendiente_r1=ingresa_e_imprime_r1(numerador,denominador);                       //LLAMA A DICHA FUNCION QUE RETORNA UN VALOR Y LO GUARDA EN pendiente_r1
	corte_r1=r1.corte(pendiente_r1);                                                //LLAMA A DICHA FUNCION QUE RETORNA UN VALOR Y LO GUARDA EN corte_r1
	if(corte_r1>=0)                                                                 //IMPRIME LA ECUACION DE LA RECTA 1
		cout<<endl<<"La ecuacion de la recta 1 es de la forma: y = "<<pendiente_r1<<"x + "<<corte_r1<<endl;
	else
		cout<<endl<<"La ecuacion de la recta 1 es de la forma: y = "<<pendiente_r1<<"x "<<corte_r1<<endl;
	cout<<endl<<"Puntos recta 2"<<endl;
	pendiente_r2=ingresa_e_imprime_r2(numerador,denominador);                       //LLAMA A DICHA FUNCION QUE RETORNA UN VALOR Y LO GUARDA EN pendiente_r2
	corte_r2=r2.corte(pendiente_r2);                                                //LLAMA A DICHA FUNCION QUE RETORNA UN VALOR Y LO GUARDA EN corte_r2
	if(corte_r2>=0)                                                                 //IMPRIME LA ECUACION DE LA RECTA 2
		cout<<endl<<"La ecuacion de la recta 2 es de la forma: y = "<<pendiente_r2<<"x + "<<corte_r2<<endl;
	else
		cout<<endl<<"La ecuacion de la recta 2 es de la forma: y = "<<pendiente_r2<<"x "<<corte_r2<<endl;
	evalua_pendiente(pendiente_r1, corte_r1, pendiente_r2, corte_r2);               //LLAMA A DICHA FUNCION
		
    return 0;
}

float ingresa_e_imprime_r1(float numerador_1, float denominador_1)                 //SE INGRESAN LOS PUNTOS DE LA RECTA 1 Y SE HALLA SU PENDIENTE
{
	float pen_r1=0;                                                                //VALOR QUE GUARDA LA PENDIENTE DE LA RECTA 1

	r1.set_punto();                                                                //ACCESE A LA CLASE RECTA Y ENTRA EN CADA UNA DE LAS FUNCIONES INDICADAS
	r1.ingresar_punto(1);
	r1.mostrar_punto(1);
	numerador_1=r1.num_pendiente(numerador_1);
	denominador_1=r1.den_pendiente(denominador_1);
	r1.set_punto();
	r1.ingresar_punto(2);
	r1.mostrar_punto(2);
    numerador_1=r1.num_pendiente(numerador_1);
	denominador_1=r1.den_pendiente(denominador_1);
	pen_r1=numerador_1/denominador_1;                                              //HALLA LA PENDIENTE DIVIDIENDO EL NUMERADOR/DENOMINADOR, QUE YA TIENEN ALMACENADOS LOS VALORES DE LAS OPERACIONES REALIZADAS EN FUNCIONES ANTERIORES
	
	return pen_r1;                                                                 //RETORNA EL VALOR DE LA PENDIENTE DE LA RECTA 1
}

float ingresa_e_imprime_r2(float numerador_1, float denominador_1)                 //SE INGRESAN LOS PUNTOS DE LA RECTA 2 Y SE HALLA SU PENDIENTE
{                               
	float pen_r2=0;                                                                //VALOR QUE GUARDA LA PENDIENTE DE LA RECTA 2
	
	r2.set_punto();                                                                //ACCESE A LA CLASE RECTA Y ENTRA EN CADA UNA DE LAS FUNCIONES INDICADAS
	r2.ingresar_punto(1);
	r2.mostrar_punto(1);
	numerador_1=r2.num_pendiente(numerador_1);
	denominador_1=r2.den_pendiente(denominador_1);
	r2.set_punto();
	r2.ingresar_punto(2);
	r2.mostrar_punto(2);	
	numerador_1=r2.num_pendiente(numerador_1);
	denominador_1=r2.den_pendiente(denominador_1);
	pen_r2=numerador_1/denominador_1;                                            //HALLA LA PENDIENTE DIVIDIENDO EL NUMERADOR/DENOMINADOR, QUE YA TIENEN ALMACENADOS LOS VALORES DE LAS OPERACIONES REALIZADAS EN FUNCIONES ANTERIORES
	
	return pen_r2;                                                               //RETORNA EL VALOR DE LA PENDIENTE DE A RECTA 2
}

void evalua_pendiente(float m1, float b1, float m2, float b2)                    //EVALUA LAS PENDIENTES
{
	if(m1==m2)                                                                   //m1 y m2 SON LAS PENDIENTES DE LA RECTA 1 Y 2 RESPECTIVAMENTE 
		cout<<endl<<"Las rectas r1 y r2 son PARALELAS."<<endl<<endl;             //INDICA SI SON PARALELAS
	else 
		if((m1*m2)==-1)
			cout<<endl<<"Las rectas r1 y r2 son PERPENDICULARES"<<endl<<endl;    //INDICA SI SON PERPENDICULARES
		else 
			halla_interseccion(m1, b1, m2, b2);                                  //LLAMA A DICHA FUNCION YA QUE SI NO SON PARALELAS NI PERPENDICULARES, HALLA LA INTERSECCION ENTRE LAS RECTAS
}

void halla_interseccion(float m1, float b1, float m2, float b2)                  //FUNCION QUE HALLA LA INTERSECCION ENTRE LAS DOS RECTAS
{
	float x_o=0, y_o=0;                                                          //VARIABLES QUE GUARDAN LA COORDENADA x Y y DEL PUNTO DE INTERSECCION
	
	x_o=((b2-b1)/(m1-m2));                                                       //OPERACION QUE HALLA COORDENADA X
	y_o=(((m1*b2*-1)+(m2*b1))/(m2-m1));                                          //OPERACION QUE HALLA COORDENADA Y
	cout<<endl<<"El PUNTO DE INTERSECCION entre las rectas es: ( "<<x_o<<" ; "<<y_o<<" )"<<endl<<endl;  //IMPRIME EL PUNTO DE INTERSECCION
}

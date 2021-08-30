
// CPP program for simpson's 1/3 rule
#include <iostream>
#include <math.h>
#include <iomanip>
#include <vector>

using namespace std;

#define PI 3.1415926535897932384626433832795

//cbrt(x)                  :Raiz cubica de x

//expoencial exp(x)        :Numero de euler elevado a x
//Exemplo: x = 2*x;
//         return exp(x);

//pow(2.7182818, (2*x)     :Potencia
//0.03*pow(x, 3)-2*x+8*sin(x + 2);


// Function to calculate f(x)
float func(float x)
{
    return 2*pow(x,3)-7*pow(x,2)+4*x+4;
} 

// Função para realizar modulo.
double modulo(double x) {
  if (x < 0) return (-x);
  else return x;
}

double derivada(double x) {
    return 6*pow(x,2)-14*x+4;
}


double derivada2(double x) {
    return 12*x-14;
}

// Function for approximate integral
float simpson_(float ll, float ul, int n, double p, int manualWay, int precision)
{
    // Calculating the value of h
    float h = (ul - ll) / n;

    // Array for storing value of x and f(x)
    float x[30], fx[30];

    if(manualWay == 0) {
        // Calculating values of x and f(x)
        for (int i = 0; i <= n; i++)
        {
            x[i] = roundf((ll + i * h) * p) / p;
            fx[i] = roundf((func(x[i])) * p) / p;
        }
    }
    else if(manualWay == 1) {
        // Reading points
        for (int i = 0; i <= n; i++)
        {
            cout << "Ponto " << i << ": ";
            cin >> x[i] >> fx[i];
        }
    }

    // Calculating result
    float res = 0;
    for (int i = 0; i <= n; i++)
    {
        if (i == 0 || i == n)
            res += (roundf(fx[i] * p) / p);
        else if (i % 2 != 0)
            res += (roundf((4 * fx[i]) * p) / p);
        else
            res += (roundf((2 * fx[i]) * p) / p);
    }
    res = (roundf(res * p) / p) * (h / 3);
    res = (roundf(res * p) / p);

    //Calculando fator erro
    const int N = n;
    float fator_erro = 0;

    float valor_sup = (-1)*(ul - ll)*(ul - ll)*(ul - ll)*(ul - ll)*(ul - ll);
    float valor_inf = (180*n*n*n*n);

    fator_erro = valor_sup/valor_inf;

    std::cout << "      ************************|RESULTADOS|************************" << "\n\n";
    std::cout << "Tabela:" << std::endl;
    int c = 0;
    cout << "i\t\tx(i)\t\ty(i)\t\tc(i)\t\ty(i)c(i)\n";
    cout << "-----------------------------------------------------------------------------\n";
    for(int i = 0; i < (n+1); i++){ 
        if(i==0 || i == n){
            c=1;
        }else if(i%3==0){
            c=2;
        }else{
            c=3;
        }
        std::cout << "i" << i << " = " << i;
        std::cout.precision(precision);
        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        std::cout << "\t\t" << "X" << i << " = " << x[i]; 
        std::cout << "\t" << "Y" << i << " = " << fx[i];
        std::cout << "\t" << "C" << i << " = " << c;
        std::cout << "\t\t" << "Y" << i << "*"<< "C"<< i << " = " << fx[i]*c << "\n\n";
        cout << noshowpoint;
    }

    std::cout <<"O valor de h e: "<< h << "\n";
    std::cout << "O valor da integracao e: " << res << "\n";
    std::cout << "Fator erro: " << fator_erro << endl << endl;
    cout << "AINDA FALTA MULTIPLICAR O FATOR DO ERRO PELA DERIVADA QUARTA NO PONTO THETA (De maior valor da funcao derivada) PARA ACHAR O ERRO!!\n\n\n";

    std::cout << "      ************************|RASCUNHO|************************" << "\n\n";

    std::cout << "CALCULO DO H: " << "\n\n";
    std::cout << "(" << ul <<"-" << ll <<")"<<"\n";
    std::cout << "-----------------" <<"   =  " << h << "\n";
    std::cout <<"    " << n <<"\n\n\n\n";

    std::cout << "CALCULO DO FATOR ERRO: " << "\n\n";
    std::cout << "\t" << "(-1)*(" << ul <<"-" << ll <<")^(5)"<<"\n";
    std::cout << "\t" << "-----------------" <<"   =  " << fator_erro << "\n";
    std::cout << "\t" << "180*" << n << "^(4)" <<"\n\n\n\n";

    std::cout << "CALCULO DO RESULTADO FINAL(INTEGRACAO): " << "\n";
    cout << "\n";
    cout << "Formula: " << "\n";
    cout << "h/3" << "( ";
    for (int i = 0; i <= n; i++)
    {
        if (i == 0){
            cout << "fx[i]" << " + ";
        }
        else if(i == n){
            cout << "fx[i]";
        }
        else if (i % 2 != 0){
            cout << "4*fx[i]" << " + ";
        }
        else{
            cout << "2*fx[i]" << " + ";
        }
    }
    cout << " )" << "\n\n";
    
    cout << h << "/3" << "( ";
    for (int i = 0; i <= n; i++)
    {
        if (i == 0){
            cout << fx[i] << " + ";
        }
        else if(i == n){
            cout << fx[i];
        }
        else if (i % 2 != 0){
            cout << "4*"<< fx[i] << " + ";
        }
        else{
            cout << "2*" <<fx[i]<< " + ";
        }
    }
    cout << " )" << "\n";

    cout << h/3 << "( ";
    for (int i = 0; i <= n; i++)
    {
        if (i == 0){
            cout << fx[i] << " + ";
        }
        else if(i == n){
            cout << fx[i];
        }
        else if (i % 2 != 0){
            cout << 4*fx[i] << " + ";
        }
        else{
            cout << 2*fx[i] << " + ";
        }
    }
    cout << " )" <<" = "<< res << "\n\n";

    return res;
}


float simpsons(float ll, float ul, int n, double p, int manualWay, int precision)
{
    // Calculating the value of h
    float h = roundf(((ul - ll) / n) * p) / p;

    // Array for storing value of x and f(x)
    float x[30], fx[30], cy[30];

    if(manualWay == 0) {
        // Calculating values of x and f(x)
        for (int i = 0; i <= n; i++)
        {
            x[i] = roundf((ll + i * h) * p) / p;
            fx[i] = roundf((func(x[i])) * p) / p;
        }
    }
    else if(manualWay == 1) {
        // Reading points
        for (int i = 0; i <= n; i++)
        {
            cout << "Ponto " << i << ": ";
            cin >> x[i] >> fx[i];
        }
    }

    float value;
    float interval_size = roundf(((ul - ll) / n) * p) / p;
    float sum = (roundf(func(ll) * p) / p) + (roundf(func(ul) * p) / p); 

    // Calculates value till integral limit

    for (int i = 1 ; i < n ; i++)
    {
        if (i % 3 == 0)
            sum = sum + 2 * (roundf(func(ll + i * interval_size) * p) / p);
        else
            sum = sum + 3 * (roundf(func(ll + i * interval_size) * p) / p);
    }
    float res = 0;
    res = (roundf((( 3 * interval_size / 8 ) * sum) * p) / p);

    //Calculando fator erro
    const int N = n;
    float fator_erro = 0;

    float valor_sup = (-1)*(ul - ll)*(ul - ll)*(ul - ll)*(ul - ll)*(ul - ll);
    float valor_inf = (80*n*n*n*n);

    fator_erro = valor_sup/valor_inf;

    std::cout << "      ************************|RESULTADOS|************************" << "\n\n";
    std::cout << "Tabela:" << std::endl;
    int c = 0;
    cout << "i\t\tx(i)\t\ty(i)\t\tc(i)\t\ty(i)c(i)\n";
    cout << "-----------------------------------------------------------------------------\n";
    for(int i = 0; i < (n+1); i++){ 
        if(i==0 || i == n){
            c=1;
        }else if(i%3==0){
            c=2;
        }else{
            c=3;
        }
        std::cout << "i" << i << " = " << i;
        std::cout.precision(precision);
        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        std::cout << "\t\t" << "X" << i << " = " << x[i]; 
        std::cout << "\t" << "Y" << i << " = " << fx[i];
        std::cout << "\t" << "C" << i << " = " << c;
        std::cout << "\t\t" << "Y" << i << "*"<< "C"<< i << " = " << fx[i]*c << "\n\n";
        cout << noshowpoint;
    }

    std::cout <<"O valor de h e: "<< h << "\n";
    std::cout << "O valor da integracao e: " << res << "\n";
    std::cout << "Fator erro: " << fator_erro << endl << endl;
    cout << "AINDA FALTA MULTIPLICAR O FATOR DO ERRO PELA DERIVADA QUARTA NO PONTO THETA (De maior valor da funcao derivada) PARA ACHAR O ERRO!!\n\n\n";

    std::cout << "      ************************|RASCUNHO|************************" << "\n\n";

    std::cout << "CALCULO DO H: " << "\n\n";
    std::cout << "(" << ul <<"-" << ll <<")"<<"\n";
    std::cout << "-----------------" <<"   =  " << h << "\n";
    std::cout <<"    " << n <<"\n\n\n\n";

    std::cout << "CALCULO DO FATOR ERRO: " << "\n\n";
    std::cout << "\t" << "(-1)*(" << ul <<"-" << ll <<")^(5)"<<"\n";
    std::cout << "\t" << "-----------------" <<"   =  " << fator_erro << "\n";
    std::cout << "\t" << "80*" << n << "^(4)" <<"\n\n\n\n";

    std::cout << "CALCULO DO RESULTADO FINAL(INTEGRACAO): " << "\n";
    cout << "\n";
    cout << "Formula: " << "\n";
    cout << "3h/8" << "( ";
    for (int i = 0; i <= n; i++)
    {
        if (i == 0){
            cout << "fx[i]" << " + ";
        }
        else if(i == n){
            cout << "fx[i]";
        }
        else if(i % 3 == 0){
            cout << "2*fx[i]";    
        }
        else{
            cout << "3*fx[i]" << " + ";
        }
    }
    cout << " )" << "\n\n";
    
    cout << h << " * 3/8" << "( ";
    for (int i = 0; i <= n; i++)
    {
        if (i == 0){
            cout << fx[i] << " + ";
        }
        else if(i == n){
            cout << fx[i];
        }
        else if(i % 3 == 0){
            cout << "2*" << fx[i]<< " + "; 
        }
        else{
            cout << "3 *" <<fx[i]<< " + ";
        }
    }
    cout << " )" << "\n";

    cout << h*3/8 << "( ";
    for (int i = 0; i <= n; i++)
    {
        if (i == 0){
            cout << fx[i] << " + ";
        }
        else if(i == n){
            cout << fx[i];
        }
        else if(i % 3 == 0){
            cout << 2*fx[i]<< " + "; 
        }
        else{
            cout << 3*fx[i] << " + ";
        }
    }
    cout << " )" <<" = "<< res << "\n\n";

    return res;
}

float trapezio(float ll, float ul, float n, double p, int manualWay, int precision)
{
    // Array for storing value of x and f(x)
    float x[30], fx[30];

    // Calculando h
    float h = (ul-ll)/n;
    
    //Declarando soma
    float s = 0;

    // Calculating values of x and f(x)

    if(manualWay == 0) {
        // Calculating values of x and f(x)
        for (int i = 0; i <= n; i++)
        { 
            x[i] = roundf( (ll + i * h) * p ) / p;
            fx[i] = roundf( func(x[i]) * p ) / p;
            if(i == 0 || i == n){
                // Computing sum of first and last terms
                // in above formula
                s += fx[i];
            }
        }
    }
    else if(manualWay == 1) {
        // Reading points
        for (int i = 0; i <= n; i++)
        {
            cout << "Ponto " << i << ": ";
            cin >> x[i] >> fx[i];
            if(i == 0 || i == n){
                s += fx[i];
            }
        }
    }

    // Adding middle terms in above formula
    for (int i = 1; i < n; i++)
        s += 2*fx[i];
 
    // h/2 indicates (b-a)/2n. Multiplying h/2
    // with s.
    s = roundf((h*s) * p ) / p;
    float Final_Result = roundf((s/2) * p ) / p;
    int c = 0;


    //Calculando fator erro
    const int N = n;
    float fator_erro = 0;

    float valor_sup = (-1)*(ul - ll)*(ul - ll)*(ul - ll);
    float valor_inf = (12*n*n);

    fator_erro = valor_sup/valor_inf;

    std::cout << "      ************************|RESULTADOS|************************" << "\n\n";
    std::cout << "Tabela:" << std::endl;
    cout << "i\t\tx(i)\t\ty(i)\t\tc(i)\t\ty(i)c(i)\n";
    cout << "-----------------------------------------------------------------------------\n";
    for(int i = 0; i < (n+1); i++){ 
        if(i==0 || i == n){
            c=1;
        }else if(i%3==0){
            c=2;
        }else{
            c=3;
        }
        std::cout << "i" << i << " = " << i;
        std::cout.precision(precision);
        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        std::cout << "\t\t" << "X" << i << " = " << x[i]; 
        std::cout << "\t" << "Y" << i << " = " << fx[i];
        std::cout << "\t" << "C" << i << " = " << c;
        std::cout << "\t\t" << "Y" << i << "*"<< "C"<< i << " = " << fx[i]*c << "\n\n";
        cout << noshowpoint;
    }

    std::cout <<"O valor de h e: "<< h << "\n";
    std::cout << "O valor da integracao e: " << Final_Result << "\n";
    std::cout << "Fator erro: " << fator_erro << endl << endl;
    cout << "AINDA FALTA MULTIPLICAR O FATOR DO ERRO PELA DERIVADA SEGUNDA NO PONTO THETA (De maior valor da funcao derivada) PARA ACHAR O ERRO!!\n\n\n";

    std::cout << "      ************************|RASCUNHO|************************" << "\n\n";

    std::cout << "CALCULO DO H: " << "\n\n";
    std::cout << "\t" << "(" << ul <<"-" << ll <<")"<<"\n";
    std::cout << "\t" << "-----------------" <<"   =  " << h << "\n";
    std::cout << "\t" << n <<"\n\n\n\n";

    std::cout << "CALCULO DO FATOR ERRO: " << "\n\n";
    std::cout << "\t" << "(-1)*(" << ul <<"-" << ll <<")^(3)"<<"\n";
    std::cout << "\t" << "-----------------" <<"   =  " << fator_erro << "\n";
    std::cout << "\t" << "12*" << n << "^(2)" <<"\n\n\n\n";

    std::cout << "CALCULO DO RESULTADO FINAL(INTEGRACAO): " << "\n";
    cout << "\n";
    cout << "Formula: " << "\n";
    cout << "h/2" << "( ";
    for (int i = 0; i <= n; i++)
    {
        if (i == 0){
            cout << "fx[" << i << "]" << " + ";
        }
        else if(i == n){
            cout << "fx[" << i << "]";
        }
        else{
            cout << "2*fx[" << i << "]" << " + ";
        }
    }
    cout << " )" << "\n\n";
    
    cout << h << "/2" << "( ";
    for (int i = 0; i <= n; i++)
    {
        if (i == 0){
            cout << fx[i] << " + ";
        }
        else if(i == n){
            cout << fx[i];
        }
        else{
            cout << "2*" <<fx[i]<< " + ";
        }
    }
    cout << " )" << "\n";

    cout << h/2 << "( ";
    for (int i = 0; i <= n; i++)
    {
        if (i == 0){
            cout << fx[i] << " + ";
        }
        else if(i == n){
            cout << fx[i];
        }
        else{
            cout << 2*fx[i] << " + ";
        }
    }
    cout << " )" <<" = "<< Final_Result << "\n\n";

    return (h/2)*s;
}

void gaussLegendre(float ll, float ul, float n, double p, int manualWay, int precision)
{
    double e1 = (ul-ll)/2;
    double e2 = (ll+ul)/2;

    vector<double> A(n);
    vector<double> t(n);
    vector<double> x(n);
    vector<double> y(n);

    if (n == 1) {
        A[0] = 2;

        t[0] = 0;
    }

    if (n == 2) {
        A[0] = A[1] = 1;

        t[0] = -0.57735;
        t[1] = -t[0];
    }

    if (n == 3) {
        A[0] = A[2] = 0.55556;
        A[1] = 0.88889;

        t[0] = -0.77460;
        t[1] = 0;
        t[2] = -t[0];
    }

    if (n == 4) {
        A[0] = A[3] = 0.34785;
        A[1] = A[2] = 0.65215;

        t[0] = -0.86114;
        t[1] = -0.33998;
        t[2] = -t[1];
        t[3] = -t[0];
    }

    if (n == 5) {
        A[0] = A[4] = 0.23693;
        A[1] = A[3] = 0.47863;
        A[2] = 0.56889;

        t[0] = -0.90618;
        t[1] = -0.53847;
        t[2] = 0;
        t[3] = -t[1];
        t[4] = -t[0];

    }


    if(manualWay == 0) {
        // Calculating values of x and f(x)
        for (int i = 0; i < n; i++)
        {
            x[i] = e1*t[i] + e2;
            y[i] = func(x[i]);
        }
    }
    else if(manualWay == 1) {
        // Reading points
        for (int i = 0; i < n; i++)
        {
            cout << "Ponto " << i << ": ";
            cin >> x[i] >> y[i];
        }
    }

    double integ = 0;

    cout << "i\t\tti\t\txi\t\tyi\t\tAi\n";
    cout << "-----------------------------------------------------------------------------\n";

    for (int i = 0; i < n; i++) {
        integ += A[i]*y[i];
        cout << i+1 << "\t\t";
        cout.setf(ios::showpoint);
        cout.setf(ios::fixed);
        cout.precision(5);
        cout << t[i] << " \t" << x[i] << " \t" << y[i] << " \t" << A[i] << endl;
        cout << noshowpoint;
    }

    integ *= e1;

    cout << endl << "Valor da integral: " << integ << endl;


    std::cout << "      ************************|RASCUNHO|************************" << "\n\n";

    std::cout << "CALCULO DO FATOR ERRO: " << "\n\n";
    // std::cout << "\t" << "(-1)*(" << ul <<"-" << ll <<")^(3)"<<"\n";
    //std::cout << "\t" << "-----------------" <<"   =  " << fator_erro << "\n";
    // std::cout << "\t" << "12*" << n << "^(2)" <<"\n\n\n\n";

    std::cout << "CALCULO DO RESULTADO FINAL(INTEGRACAO): " << "\n";
    cout << "\n";
    cout << "Formula: " << "\n";
    cout << "(ul - ll)/2" << "[ ";
    for (int i = 0; i < n; i++)
    {
        if(i < n-1){
            cout << "(A[" << i << "]" << " * " << "Y[" << i << "])" << " + ";
        }
        else{
            cout << "(A[" << i << "]" << " * " << "Y[" << i << "])";
        }
    }
    cout << " ]" << "\n\n";
    
    cout << (ul - ll) << "/2" << "[ ";
    for (int i = 0; i < n; i++)
    {
        if(i < n-1){
            cout << "(" << A[i] << " * " << y[i] << ")" << " + ";
        }
        else{
            cout << "(" << A[i] << " * " << y[i] << ")";
        }
    }
    cout << " ]" << "\n";

    cout << (ul - ll)/2 << "[ ";
    for (int i = 0; i < n; i++)
    {
        if(i < n-1){
            cout << "(" << A[i] * y[i] << ")" << " + ";
        }
        else{
            cout << "(" << A[i] *  y[i] << ")";
        }
    }
    cout << " ]" <<" = "<< integ << "\n\n";
}

void bissecao (float a, float b, double p, int precision){
    //ALTERE AS VARIAVEIS A SEGUIR DE ACORDO COM OS DADOS FORNECIDOS -------------------------------------------------------------------------------------------------------------------
    float toler = 0.01;
    int iter_max = 10;
    // float a = 0;
    // float b = 1;

//---------------------------------------------------------------------------------------------------------------------------------------------

    int iter = 0;


	float x = 0;

	float fa = func(a);
    fa = roundf(fa * p) / p;
	float fb = func(b);
    fb = roundf(fb * p) / p;
	float fx = func(x);
    fx = roundf(fx * p) / p;


	if (func(a)*func(b) > 0) {
		std::cout << "funcao nao muda de sinal neste intervalo" << std::endl;
		system("PAUSE");
		exit(1);
	}
	float deltaX = modulo(b - a);


	std::cout << "iter\ta\t\tFa\t\tb\t\tFb\t\tx\t\tFx\t\tdeltaX" << std::endl;
	std::cout << "-------------------------------------------------------------------------------------------------------------------\n";
	std::cout.precision(precision);
	std::cout.setf(std::ios::fixed);

	while (1) {
		deltaX /= 2.0;
		x = (a + b)/2.0;
        x = roundf(x * p) / p;
		fx = func(x);


        if(fa < 0 && fx > 0) {
            std::cout << iter << " \t" << a << " \t\t" << fa << " \t" << b << " \t\t" << fb << " \t\t" << x << " \t\t" << fx << " \t\t" << deltaX << std::endl;
        }
        else if(fa < 0) {
		    std::cout << iter << " \t" << a << " \t\t" << fa << " \t" << b << " \t\t" << fb << " \t\t" << x << " \t\t" << fx << " \t" << deltaX << std::endl;
        }
        else if(fx > 0) {
		    std::cout << iter << " \t" << a << " \t" << fa << " \t" << b << " \t\t" << fb << " \t\t" << x << " \t\t" << fx << " \t\t" << deltaX << std::endl;
        }
        else {
	        std::cout << iter << " \t" << a << " \t" << fa << " \t" << b << " \t\t" << fb << " \t\t" << x << " \t\t" << fx << " \t" << deltaX << std::endl;
        }

		if (((modulo(fx) <= toler) && (deltaX <= toler)) || (iter >= iter_max)) break;

		if (fa*fx > 0) {
            a = x;
            fa = fx;
		}
		else {
            b = x;
            fb = fx;
		}
		iter++;
	}
	double raiz = x;
	if (modulo(func(x)) <= toler && (deltaX <= toler)) {
		std::cout << std::endl << "Raiz encontrada: " << raiz << std::endl;
		std::cout << "Iter: " << iter << "\n\n";

	}

	else {
		std::cout << "A raiz nao pode ser encontrada com os criterios fornecidos." << std::endl;
		std::cout << "Iter: " << iter << "\n\n";
	}

}

void secante (float a, float b, double p, int precision) {
    double epsilon =2.2204e-16;

    float a0 = a;
    float b0 = b;
    double toler = 0.01;
    int iter_max = 10;

    float x = 0;
    int iter = 0;
    float raiz = 0;

    float fa = func(a);
    fa = roundf(fa * p) / p;
    float fb = func(b);
    fb = roundf(fb * p) / p;
    float fx = 0;

    float deltaX = 0;
    std::cout << "iter\ta\t\tFa\t\tb\t\tFb\t\tx\t\tFx\t\tdeltaX" << std::endl;
    std::cout << "-------------------------------------------------------------------------------------------------------------------\n";
    std::cout.precision(precision);
    std::cout.setf(std::ios::fixed);

    while(1) {
        deltaX = fb*(b-a)/(fb-fa);
        deltaX = roundf(deltaX * p) / p;
        x = b - deltaX;
        fx = func(x);

        if(fa < 0 && fb < 0) {
            std::cout << iter << " \t" << a << " \t\t" << fa << " \t" << b << " \t\t" << fb << " \t" << x << " \t\t" << fx << " \t\t" << deltaX << std::endl;
        }
        else if(fa < 0) {
            std::cout << iter << " \t" << a << " \t\t" << fa << " \t" << b << " \t\t" << fb << " \t\t" << x << " \t\t" << fx << " \t\t" << deltaX << std::endl;
        }
        else if(fb < 0) {
            std::cout << iter << " \t" << a << " \t\t" << fa << " \t\t" << b << " \t\t" << fb << " \t" << x << " \t\t" << fx << " \t\t" << deltaX << std::endl;
        } 
        else if(fx < 0) {
            std::cout << iter << " \t" << a << " \t\t" << fa << " \t\t" << b << " \t\t" << fb << " \t\t" << x << " \t\t" << fx << " \t" << deltaX << std::endl;
        } else
        std::cout << iter << " \t" << a << " \t\t" << fa << " \t\t" << b << " \t\t" << fb << " \t\t" << x << " \t\t" << fx << " \t\t" << deltaX << std::endl;

        if (((modulo(deltaX)<= toler) || (modulo(fx) <= toler)) || (modulo(fb-fx) < epsilon) || (iter >= iter_max))
        break;

        a = b;
        fa = fb;
        b = x;
        fb = fx;
        iter++;
    }

    raiz = x;

    if ((modulo(deltaX) <= toler) || (modulo(fx) <= toler)) {
        if ((raiz >= a0) && (raiz <= b0)) {
            std::cout << "Raiz encontrada: ";
        }
        else {
            std::cout << "Raiz encontrada fora do intervalo: ";
        }
    }
    else {
        std::cout << "A raiz nao pode ser encontrada." << std::endl;
        exit(0);
    }

    std::cout << raiz << std::endl << "Numero de iteracoes: " << iter << std::endl;
}

void pegaso (float a, float b, double p, int precision) {
    float a0 = a;
    float b0 = b;
    double toler = 0.01;
    int iter_max = 10;

    float x = 0;
    int iter = 0;
    float raiz = 0;

    float fa = func(a);
    fa = roundf(fa * p) / p;
    float fb = func(b);
    fb = roundf(fb * p) / p;
    float fx = 0;

    float deltaX = 0;

    std::cout << "iter\ta\t\tFa\t\tb\t\tFb\t\tx\t\tFx\t\tdeltaX" << std::endl;
    std::cout << "-------------------------------------------------------------------------------------------------------------------\n";
    std::cout.precision(precision);
    std::cout.setf(std::ios::fixed);

    while(1) {
        deltaX = fb*(b-a)/(fb-fa);
        deltaX = roundf(deltaX * p) / p;
        x = b - deltaX;
        fx = func(x);

        if(fa < 0 && fb < 0) {
            std::cout << iter << " \t" << a << " \t\t" << fa << " \t" << b << " \t\t" << fb << " \t" << x << " \t\t" << fx << " \t\t" << deltaX << std::endl;
        }
        else if(fa < 0) {
            std::cout << iter << " \t" << a << " \t\t" << fa << " \t" << b << " \t\t" << fb << " \t\t" << x << " \t\t" << fx << " \t\t" << deltaX << std::endl;
        }
        else if(fb < 0) {
            std::cout << iter << " \t" << a << " \t\t" << fa << " \t\t" << b << " \t\t" << fb << " \t" << x << " \t\t" << fx << " \t\t" << deltaX << std::endl;
        } 
        else if(fx < 0) {
            std::cout << iter << " \t" << a << " \t\t" << fa << " \t\t" << b << " \t\t" << fb << " \t\t" << x << " \t\t" << fx << " \t" << deltaX << std::endl;
        } else
        std::cout << iter << " \t" << a << " \t\t" << fa << " \t\t" << b << " \t\t" << fb << " \t\t" << x << " \t\t" << fx << " \t\t" << deltaX << std::endl;

        if (((modulo(deltaX)<= toler) && (modulo(fx) <= toler)) || (iter >= iter_max))
        break;

        if (fb*fx < 0) {
        a = b;
        fa = fb;
        }
        else {
        fa *= fb/(fb+fx);
        }
        b = x;
        fb = fx;
        iter++;
    }

    raiz = x;

    if ((modulo(deltaX) <= toler) && (modulo(fx) <= toler)) {
        std::cout << "Raiz encontrada: " << raiz << std::endl;
        std::cout << "Numero de iteracoes: " << iter << std::endl;
    }
    else {
        std::cout << "A raiz nao pode ser encontrada." << std::endl;
    }
}

void halley(double p, int precision){
  double epsilon = 2.2204e-16;
  double toler = 0.00001;
  double deltaX = 1+toler;
  int iter_max = 10;
  int iter = 0;

  double raiz = 0;

  std::cout << "k\tx_k\t\tFx_k\t\tDfx_k\t\tdeltaX_k" << std::endl;
  std::cout << "-------------------------------------------------------------------------------------------------------------------\n";
  std::cout.precision(precision);
  std::cout.setf(std::ios::fixed);

  double x = 2;
  double fx = 0;
  double dfx = 0;
  double dfx2 = 0;

  while(1) {
    fx = func(x);
    fx = roundf(fx * p) / p;
    dfx = derivada(x);
    dfx = roundf(dfx * p) / p;
    dfx2 = derivada2(x);
    dfx2 = roundf(dfx2 * p) / p;
    deltaX = (2*fx*dfx)/(2*dfx*dfx - fx*dfx2);

    std::cout << iter << " \t" << x << " \t" << fx << " \t" << dfx << " \t" << deltaX << std::endl;

    if (((modulo(deltaX)<= toler) && (modulo(fx) <= toler)) || (modulo(dfx) < epsilon) ||(iter >= iter_max)) break;

    x -= deltaX;
    x = roundf(x*p) / p;

    iter++;
  }

  raiz = x;

  if ((modulo(deltaX) <= toler) && (modulo(fx) <= toler)) {
    std::cout << "Raiz encontrada: " << raiz << std::endl;
    std::cout << "Numero de iteracoes: " << iter << std::endl;
  }
  else {
    std::cout << "A raiz nao pode ser encontrada." << std::endl;
  }
}

void newtowRaphson(double p, int precision){
  double epsilon =2.2204e-16;
  double toler = 0.00001;
  double deltaX = 1+toler;
  int iter_max = 10;
  int iter = 0;

  double raiz = 0;

  std::cout << "k\tx_k\t\tFx_k\t\tDfx_k\t\tdeltaX_k" << std::endl;
  std::cout << "-------------------------------------------------------------------------------------------------------------------\n";
  std::cout.precision(precision-1);
  std::cout.setf(std::ios::fixed);

  double x = 2;
  double fx = 0;
  double dfx = 0;

  while(1) {
    fx = func(x);
    fx = roundf(fx * p) / p;
    dfx = derivada(x);
    dfx = roundf(dfx * p) / p;
    deltaX = fx/dfx;

    std::cout << iter << " \t" << x << " \t" << fx << " \t" << dfx << " \t" << deltaX << std::endl;

    if (((modulo(deltaX)<= toler) && (modulo(fx) <= toler)) || (modulo(dfx) < epsilon) ||(iter >= iter_max)) break;

    x -= deltaX;
    x = roundf(x*p) / p;
    iter++;
  }

  raiz = x;

  if ((modulo(deltaX) <= toler) && (modulo(fx) <= toler)) {
    std::cout << "Raiz encontrada: " << raiz << std::endl;
    std::cout << "Numero de iteracoes: " << iter << std::endl;
  }
  else {
    std::cout << "A raiz nao pode ser encontrada." << std::endl;
  }
}

void regulaFalsi(float a, float b, int p, int precision) {

  double a0 = a;
  double b0 = b;
  double toler = 1e-3;
  int iter_max = 10;

  double x = 0;
  int iter = 0;
  double raiz = 0;

  double fa = func(a);
  double fb = func(b);
  double fx = 0;

  double deltaX = 0;

  if (func(a)*func(b) > 0) {
		std::cout << "funcao nao muda de sinal neste intervalo" << std::endl;
		system("PAUSE");
		exit(0);
	}

  std::cout << "iter\ta\t\tFa\t\tb\t\tFb\t\tx\t\tFx\t\tdeltaX" << std::endl;
  std::cout << "-------------------------------------------------------------------------------------------------------------------\n";
  std::cout.precision(precision-1);
  std::cout.setf(std::ios::fixed);

  while(1) {
    deltaX = fb*(b-a)/(fb-fa);
    deltaX = roundf(deltaX * p) / p;
    x = b - deltaX;
    x = roundf(x * p) / p;
    fx = func(x);
    fx = roundf(fx * p) / p;
    std::cout << iter << " \t" << a << " \t" << fa << " \t" << b << " \t" << fb << " \t" << x << " \t" << fx << " \t" << deltaX << std::endl;

    if (((modulo(deltaX)<= toler) && (modulo(fx) <= toler)) || (iter >= iter_max))
      break;

    if (fb*fx < 0) {
      a = roundf(b * p) / p;
      fa = roundf(fb * p) / p;
    }
    b = x;
    b = roundf(b * p) / p;
    fb = fx;
    fb = roundf(fb * p) / p;
  }
}

void shroder(double p, int precision) {
    // ALTERE AS VARIAVEIS A SEGUIR -----------------------------------------------------------------------------------------------------------------

  double toler = 0.01;
  double x = 6.5;
  int iter_max = 10;
  int m = 2;

//------------------------------------------------------------------------------------------------------------------------------------

  double epsilon =2.2204e-16;
  double deltaX = 1 + toler;
  int iter = 0;
  double raiz = 0;

  std::cout << "k\tx_k\t\tFx_k\t\tDfx_k\t\tdeltaX_k" << std::endl;
  std::cout << "-------------------------------------------------------------------------------------------------------------------\n";
  std::cout.precision(precision);
  std::cout.setf(std::ios::fixed);


  float fx = 0;
  float dfx = 0;

  while(1) {
    fx = func(x);
    fx = roundf(fx * p) / p;
    dfx = derivada(x);
    dfx = roundf(dfx * p) / p;


    std::cout << iter << " \t" << x << " \t\t" << fx << " \t\t" << dfx << " \t\t" << deltaX << std::endl;

    if (((modulo(deltaX)<= toler) && (modulo(fx) <= toler)) || (modulo(dfx) < epsilon) ||(iter >= iter_max)) break;


    deltaX = m*fx/dfx;
    deltaX = roundf(deltaX * p) / p;
    x -= deltaX;
    x = roundf(x*p) / p;

    iter++;
  }

  raiz = x;

  if ((modulo(deltaX) <= toler) && (modulo(fx) <= toler)) {
    std::cout << "Raiz encontrada: " << raiz << std::endl;
    std::cout << "Numero de iteracoes: " << iter << std::endl;
  }
  else {
    std::cout << "A raiz nao pode ser encontrada." << std::endl;
  }
}

// Driver program
int main()
{
    float lower_limit = 0; // Lower limit
    float upper_limit = 0; // Upper limit
    int n = 0;               // Number of interval
    double p = 0;
    int manualWay = 0;
    cout << "Entre limite inferior de integracao: ";
    cin >> lower_limit;
    cout << "Entre superior inferior de integracao: ";
    cin >> upper_limit;
    cout << "Entre numero de sub intervalos ou numero de pontos no caso de Gauss Legendre: ";
    cin >> n;
    cout << "Precisao de casas decimais: ";
    cin >> p;
    cout << "Modo manual(true = 1 or false = 0): ";
    cin >> manualWay;

    int precision = p;
    p = pow(10, (p));
    char type;
    cout << "\n" 
    <<"Qual programa sera utilizado ? " 
    << "\n\n" 
    << "1: 1/3 de simpson" << "\n" 
    << "2: Trapezio" << "\n" 
    << "3: 3/8 de simpsons" << "\n"
    << "4: Gauss Legendre" << "\n"
    << "5: Bissecao" << "\n"
    << "6: Secante" << "\n"
    << "7: Pegaso" << "\n"
    << "8: Halley" << "\n"
    << "9: Newton-Raphson" << "\n"
    << "a: Shroder" << "\n"
    << "b: Regula Falsi" << "\n\n";

    std::cin >> type;
    switch (type) {
        case '1':
            simpson_(lower_limit, upper_limit, n, p, manualWay, precision);
            break;
        case '2':
            trapezio(lower_limit, upper_limit, n, p,manualWay, precision);
            break;
        case '3':
            simpsons(lower_limit, upper_limit, n, p,manualWay, precision);
            break;
        case '4':
            gaussLegendre(lower_limit, upper_limit, n, p,manualWay, precision);
            break;
        case '5':
            bissecao(lower_limit, upper_limit, p, precision);
            break;
        case '6':
            secante(lower_limit, upper_limit, p, precision);
            break;
        case '7':
            pegaso(lower_limit, upper_limit, p, precision);
            break;
        case '8':
            halley(p, precision);
            break;
        case '9':
            newtowRaphson(p, precision);
            break;
        case 'a':
            shroder(p, precision);
            break;
        case 'b':
            regulaFalsi(lower_limit, upper_limit, p, precision);
            break;
        default: std::cerr << "Invalid type\n";        
    }

    return 0;
}
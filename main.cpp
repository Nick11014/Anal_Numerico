
// CPP program for simpson's 1/3 rule
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

#define PI 3.1415926535897932384626433832795

//cbrt(x)                  :Raiz cubica de x

//expoencial exp(x)        :Numero de euler elevado a x
//Exemplo: x = 2*x;
//         return exp(x);

//pow(2.7182818, (2*x)     :Potencia


// Function to calculate f(x)
float func(float x)
{
    return exp(x*x);
} 

// Função para realizar modulo.
double modulo(double x) {
  if (x < 0) return (-x);
  else return x;
}

// Function for approximate integral
float simpson_(float ll, float ul, int n, int p, int manualWay, int precision)
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
    cout << "AINDA FALTA MULTIPLICAR O FATOR DO ERRO PELA DERIVADA NO PONTO THETA PARA ACHAR O ERRO!!\n\n\n";

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


float simpsons(float ll, float ul, int n, int p, int manualWay, int precision)
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
    cout << "AINDA FALTA MULTIPLICAR O FATOR DO ERRO PELA DERIVADA NO PONTO THETA PARA ACHAR O ERRO!!\n\n\n";

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

<<<<<<< Updated upstream
float trapezio(float ll, float ul, float n, int p,int manualWay)
{   
=======
float trapezio(float ll, float ul, float n, int p, int manualWay, int precision)
{
>>>>>>> Stashed changes
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
    cout << "AINDA FALTA MULTIPLICAR O FATOR DO ERRO PELA DERIVADA NO PONTO THETA PARA ACHAR O ERRO!!\n\n\n";

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

// Driver program
int main()
{
    float lower_limit = 0; // Lower limit
    float upper_limit = 0; // Upper limit
    int n = 0;               // Number of interval
    int p = 0;
    int manualWay = 0;
    cout << "Entre limite inferior de integracao: ";
    cin >> lower_limit;
    cout << "Entre superior inferior de integracao: ";
    cin >> upper_limit;
    cout << "Entre numero de sub intervalos: ";
    cin >> n;
    cout << "Precisao de casas decimais: ";
    cin >> p;
    cout << "Modo manual(true = 1 or false = 0): ";
    cin >> manualWay;

    int precision = p;
    p = pow(10, (p));
    char type;
    cout << "\n" <<"Qual programa sera utilizado ? " << "\n\n" << "1: 1/3 de simpson" << "\n" 
    << "2: Trapezio" << "\n" << "3: 3/8 de simpsons" << "\n";
  std::cin >> type;
  switch (type) {
    case '1':
<<<<<<< Updated upstream
        simpson_(lower_limit, upper_limit, n, p, manualWay);
        break;
    case '2':
        trapezio(lower_limit, upper_limit, n, p,manualWay);
        break;
    case '3':
        simpsons(lower_limit, upper_limit, n, p,manualWay);
         break;
=======
      simpson_(lower_limit, upper_limit, n, p, manualWay, precision);
      break;
    case '2':
      trapezio(lower_limit, upper_limit, n, p,manualWay, precision);
      break;
    case '3':
      simpsons(lower_limit, upper_limit, n, p,manualWay, precision);
      break;
>>>>>>> Stashed changes
    default: std::cerr << "Invalid type\n";
  }

    return 0;
}
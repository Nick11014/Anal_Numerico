
// CPP program for simpson's 1/3 rule
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

//cbrt(x)                  :Raiz cubica de x

//expoencial exp(x)        :Numero de euler elevado a x
//Exemplo: x = 2*x;
//         return exp(x);

//pow(2.7182818, (2*x)     :Potencia


// Function to calculate f(x)
float func(float x)
{   x = pow(x, (2));
    return exp(x);
} 

// Function for approximate integral
float simpsons_(float ll, float ul, int n, int p)
{
    // Calculating the value of h
    float h = (ul - ll) / n;

    // Array for storing value of x and f(x)
    float x[10], fx[10];

    // Calculating values of x and f(x)
    for (int i = 0; i <= n; i++)
    {
        x[i] = ll + i * h;
        fx[i] = func(x[i]);
    }

    // Calculating result
    float res = 0;
    for (int i = 0; i <= n; i++)
    {
        if (i == 0 || i == n)
            res += fx[i];
        else if (i % 2 != 0)
            res += 4 * fx[i];
        else
            res += 2 * fx[i];
    }
    res = res * (h / 3);

    cout << fixed << setprecision(p);

    std::cout << "      ************************|RESULTADOS|************************" << "\n\n";
    std::cout << "Tabela:" << std::endl;
    int c = 0;
    for(int i = 0; i < (n+1); i++){ 
        if(i==0 || i == n){
            c=1;
        }else if(i%2==0){
            c=2;
        }else{
            c=4;
        }
        std::cout << "i" << i << " = " << i;
        std::cout << "           X" << i << " = " << x[i]; 
        std::cout << "           Y" << i << " = " << fx[i];
        std::cout << "           C" << i << " = " << c;
        std::cout << "           Y" << i << "*"<< "C"<< i << " = " << fx[i]*c << "\n\n";
    }

    std::cout <<"O valor de h e: "<< h << "\n";
    std::cout << "O valor da integracao e: " << res << "\n\n";

    std::cout << "      ************************|RASCUNHO|************************" << "\n\n";

    std::cout << "CALCULO DO H: " << "\n\n";
    std::cout << "(" << ul <<"-" << ll <<")"<<"\n";
    std::cout << "-----------------" <<"   =  " << h << "\n";
    std::cout <<"    " << n <<"\n\n\n\n";

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














float trapezio(float ll, float ul, float n, int p)
{
    // Array for storing value of x and f(x)
    float x[10], fx[10];

    // Calculando h
    float h = (ul-ll)/n;
    
    //Declarando soma
    float s = 0;

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

    // Adding middle terms in above formula
    for (int i = 1; i < n; i++)
        s += 2*fx[i];
 
    // h/2 indicates (b-a)/2n. Multiplying h/2
    // with s.
    s = roundf((h*s) * p ) / p;
    float Final_Result = roundf((s/2) * p ) / p;
    int c = 0;

    std::cout << "      ************************|RESULTADOS|************************" << "\n\n";
    std::cout << "Tabela:" << std::endl;

    for(int i = 0; i < (n+1); i++){ 
        if(i==0 || i == n){
            c=1;
        }else{
            c=2;
        }
        std::cout << "i" << i << " = " << i;
        std::cout << "           X" << i << " = " << x[i]; 
        std::cout << "           Y" << i << " = " << fx[i];
        std::cout << "           C" << i << " = " << c;
        std::cout << "           Y" << i << "*"<< "C"<< i << " = " << fx[i]*c << "\n\n";
    }

    std::cout <<"O valor de h e: "<< h << "\n";
    std::cout << "O valor da integracao e: " << Final_Result << "\n\n";

    std::cout << "      ************************|RASCUNHO|************************" << "\n\n";

    std::cout << "CALCULO DO H: " << "\n\n";
    std::cout << "(" << ul <<"-" << ll <<")"<<"\n";
    std::cout << "-----------------" <<"   =  " << h << "\n";
    std::cout <<"    " << n <<"\n\n\n\n";

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
    cout << "Entre limite inferior de integracao: ";
    cin >> lower_limit;
    cout << "Entre superior inferior de integracao: ";
    cin >> upper_limit;
    cout << "Entre numero de sub intervalos: ";
    cin >> n;
    cout << "Entre precisao: ";
    cin >> p;

    p = pow(10, (p));
    char type;
    cout << "\n" <<"Qual programa sera utilizado ?: " << "\n\n" << "1: 1/3 de simpson" << "\n" << "2: Trapezio" << "\n";
  std::cin >> type;
  switch (type) {
    case '1':
      simpsons_(lower_limit, upper_limit, n, p);
      break;
    case '2':
      trapezio(lower_limit, upper_limit, n, p);
      break;
    default: std::cerr << "Invalid type\n";
  }

    return 0;
}
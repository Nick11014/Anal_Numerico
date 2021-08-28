
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
{
    x = (-pow(x,2)/2);
    x = exp(x);
    float temp = 2 * 3.1415;
    float aux = pow(temp, 0.5);
    return x / aux;
} 

// Function for approximate integral
float simpson_(float ll, float ul, int n, int p, int manualWay)
{
    // Calculating the value of h
    float h = (ul - ll) / n;

    // Array for storing value of x and f(x)
    float x[10], fx[10];

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
    res = (roundf(res * p) / p) * (roundf((h / 3) * p) / p);
    res = (roundf(res * p) / p);

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


float simpsons(float ll, float ul, int n, int p, int manualWay)
{
    // Calculating the value of h
    float h = roundf(((ul - ll) / n) * p) / p;

    // Array for storing value of x and f(x)
    float x[10], fx[10], cy[10];

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

    std::cout << "      ************************|RESULTADOS|************************" << "\n\n";
    std::cout << "Tabela:" << std::endl;
    int c = 0;
    for(int i = 0; i < (n+1); i++){ 
        if(i==0 || i == n){
            c=1;
        }else if(i%3==0){
            c=2;
        }else{
            c=3;
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

float trapezio(float ll, float ul, float n, int p,int manualWay)
{
    // Array for storing value of x and f(x)
    float x[10], fx[10];

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

    p = pow(10, (p));
    char type;
    cout << "\n" <<"Qual programa sera utilizado ?: " << "\n\n" << "1: 1/3 de simpson" << "\n" 
    << "2: Trapezio" << "\n" << "3: 3/8 de simpsons";
  std::cin >> type;
  switch (type) {
    case '1':
      simpson_(lower_limit, upper_limit, n, p, manualWay);
      break;
    case '2':
      trapezio(lower_limit, upper_limit, n, p,manualWay);
      break;
    case '3':
      simpsons(lower_limit, upper_limit, n, p,manualWay);
      break;
    default: std::cerr << "Invalid type\n";
  }

    return 0;
}
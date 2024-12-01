#include <iostream>
using namespace std;
int sgn(double x) 
{
    if (x > 0) return 1;
    if (x < 0) return -1;
    return 0;
}
void getQ(double &a, double &b, double &c) 
{
    cout << "Enter a (coefficient of x^2): ";
    cin >> a;
    cout << "Enter b (coefficient of x): ";
    cin >> b;
    cout << "Enter c (constant term): ";
    cin >> c;
    cout << a << "x^2 + " << b << "x + " << c;
}
void find_roots(double a, double b, double c) 
{
    if (a == 0) 
    {
        cout << "This is not a quadratic equation.\n";
        return;
    }
    double delta = pow(b, 2) - 4 * a * c;
    if (delta > 0) 
    {
        double root1 = (-b + sqrt(delta)) / (2 * a);
        double root2 = (-b - sqrt(delta)) / (2 * a);
        cout << "The function has roots at: (" << root1 << ", 0) and (" << root2 << ", 0).\n";
    }
    else if (delta == 0) 
    {
        double root = -b / (2 * a);
        cout << "The function has a double root at: (" << root << ", 0).\n";
    }
    else 
    {
        cout << "The function has no real roots.\n";
    }
}
void evaluate_at_x(double a, double b, double c) 
{
    double x;
    cout << "Enter the value of x: ";
    cin >> x;
    double value = a * pow(x, 2) + b * x + c;
    cout << "The value of the function at x = " << x << " is " << value << ".\n";
}
void find_derivative(double a, double b) 
{
    if (a == 0 && b == 0) 
    {
        cout << "The derivative is 0 (constant function).\n";
        return;
    }
    cout << "The derivative of the function is: " << 2 * a << "x + " << b << "\n";
}
void tangent_eq(double a, double b, double c) 
{
    double x0;
    cout << "Enter the x-coordinate: ";
    cin >> x0;
    double slope = 2 * a * x0 + b;
    double intercept = (a * pow(x0, 2) + b * x0 + c) - slope * x0;
    cout << "The equation of the tangent line is: y = " << slope << "x + " << intercept << "\n";
}
void normal_eq(double a, double b, double c) 
{
    double x0;
    cout << "Enter the x-coordinate: ";
    cin >> x0;
    double slope = 2 * a * x0 + b;
    if (slope == 0) 
    {
        cout << "The normal line is vertical at x = " << x0 << ".\n";
        return;
    }
    double normal_slope = -1 / slope;
    double intercept = (a * pow(x0, 2) + b * x0 + c) - normal_slope * x0;
    cout << "The equation of the normal line is: y = " << normal_slope << "x + " << intercept << "\n";
}
void function_behav(double a, double b, double c) {
    if (a == 0) 
    {
        cout << "This is not a quadratic function.\n";
        return;
    }
    double delta = pow(b, 2) - 4 * a * c;
    if (delta > 0)
    {
        double root1 = (-b + sqrt(delta)) / (2 * a);
        double root2 = (-b - sqrt(delta)) / (2 * a);
        if (a > 0) 
        {
            cout << "The function is positive on (-inf, " << root2 << ") U (" << root1 << ", inf).\n";
            cout << "The function is negative on (" << root2 << ", " << root1 << ").\n";
        }
        else 
        {
            cout << "The function is negative on (-inf, " << root2 << ") U (" << root1 << ", inf).\n";
            cout << "The function is positive on (" << root2 << ", " << root1 << ").\n";
        }
    }
    else if (delta == 0) 
    {
        double root = -b / (2 * a);
        if (a > 0) 
        {
            cout << "The function is positive on (-inf, " << root << ") U (" << root << ", inf).\n";
        }
        else 
        {
            cout << "The function is negative on (-inf, " << root << ") U (" << root << ", inf).\n";
        }
    }
    else {
        if (a > 0) 
        {
            cout << "The function is positive on all real numbers (R).\n";
        }
        else 
        {
            cout << "The function is negative on all real numbers (R).\n";
        }
    }
}

int main() 
{
    double a, b, c;
    getQ(a, b, c);

    while (true) 
    {
        cout << "\nChoose an operation:\n";
        cout << "[1] Evaluate the function at a point\n";
        cout << "[2] Find roots of the function\n";
        cout << "[3] Find the derivative\n";
        cout << "[4] Find the tangent line at a point\n";
        cout << "[5] Find the normal line at a point\n";
        cout << "[6] Analyze the behavior of the function\n";
        cout << "[7] Exit\n";

        int choice;
        cin >> choice;

        switch (choice) 
        {
        case 1:
            evaluate_at_x(a, b, c);
            break;
        case 2:
            find_roots(a, b, c);
            break;
        case 3:
            find_derivative(a, b);
            break;
        case 4:
            tangent_eq(a, b, c);
            break;
        case 5:
            normal_eq(a, b, c);
            break;
        case 6:
            function_behav(a, b, c);
            break;
        case 7:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
}
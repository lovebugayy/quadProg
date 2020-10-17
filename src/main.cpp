#include<iostream>
#include<sstream>
#include<string>
#include "Array.h"
#include "QuadProg.h"
#include <eigen3/Eigen/Eigen>

using namespace std;
using namespace quadprogpp;

int main()
{
    quadprogpp::Matrix<double> CE, CI;
    quadprogpp::Vector<double> ce0, ci0, x;
    int n,m,p;
    double sum = 0.0;
    char ch;

    n = 2;

   std::vector<std::vector<double> >  b{ {4,1},{1,2} };
    quadprogpp::Matrix<double>  G(b, 2, 2);
  /*  G.resize(2, 2);
    {
        std::istringstream is("4,1,"
            "1,2");
        for (auto i = 0; i < n; i++)
            for (auto j = 0; j < n; j++)
                is >> G[i][j] >> ch;
    }*/


    /*quadprogpp::Vector<double> g0;
    {
        std::istringstream is("1,1");
        for (auto i = 0; i < n; i++)
            is >> g0[i] >> ch;
    }*/
    std::vector<double> a;
    a.push_back(1);   a.push_back(1);
    quadprogpp::Vector<double> g0(a,2);

    p = 1;
    CE.resize(n, p);
    {
        std::istringstream is("1.0,"
                              "1.0");
        for (auto  i = 0; i < n; i++)
            for (int  j = 0; j < p; j++)
                is >> CE[i][j] >> ch;
    }

    ce0.resize(p);
    {
        std::istringstream is("-1");
        for (int i = 0; i < p; i++)
            is >> ce0[i] >> ch;
    }

    m=2;
    CI.resize(n, m);
    {
        std::istringstream is("1.0, 0.0,"
                              "0.0,1.0");
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                is >> CI[i][j] >> ch;
    }

    ci0.resize(m);
    {
        std::istringstream is("0,0");
        for (int i = 0; i < m; i++)
            is >> ci0[i] >> ch;
    }

    x.resize(n);
    //auto f = quadprogpp::solve_quadprog(G, g0, CE, ce0, CI, ci0, x);
    cout << "f:" << quadprogpp::solve_quadprog(G, g0, CE, ce0, CI, ci0, x)  << endl;
    cout << "x:" << x << endl;

/*
    Eigen::VectorXd a_a;
    a_a.resize(5);
    for(auto i=0;i<5;i++)
        a_a(i)=i;
    quadprogpp::Vector<double> y(a_a,5);
    cout<<y<<endl;


    Eigen::MatrixXd b_b(2,2);
    for(auto i=0;i<2;i++)
    {
        for(auto j=0;j<2;j++)
        {
            b_b(i,j)=static_cast<double> (2*i*j);
        }
    }

    quadprogpp::Matrix<double> z(b_b,2,2);
    cout<<z<<endl;*/
    return 0;
}

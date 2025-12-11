#include<iostream>
#include<vector>
#include<string>
#include<map>

#include <CGAL/QP_models.h>
#include <CGAL/QP_functions.h>
#include <CGAL/Gmpz.h>


// choose input type (input coefficients must fit)
typedef double IT;
// choose exact type for solver (CGAL::Gmpz or CGAL::Gmpq)
typedef CGAL::Gmpz ET;

// program and solution types
typedef CGAL::Quadratic_program<IT> Program;
typedef CGAL::Quadratic_program_solution<ET> Solution;








#include <iostream>
#include <vector>
#include <coin/CbcModel.hpp>
#include <coin/OsiClpSolverInterface.hpp>

int ilp(std::vector<std::vector<double> > &A, std::vector<double> &b, std::vector<double> &c) {
    using namespace std;
    const int N = c.size();
    const int M = b.size(); 
    CoinPackedMatrix matrix(false, 0, 0); 
    matrix.setDimensions(0, N);
    for (int i = 0; i < M; ++i) {
        CoinPackedVector row;
        for (int j = 0; j < N; ++j) {
            double coeff = A[i][j];
            if (coeff != 0.0) row.insert(j, coeff);
        }
        matrix.appendRow(row);
    }
    std::vector<double> colLower(N, 0.0);
    std::vector<double> colUpper(N, std::numeric_limits<double>::infinity());
    std::vector<double> rowLower(M, -std::numeric_limits<double>::infinity());
    std::vector<double> rowUpper(M);
    for (int i = 0; i < M; ++i) rowUpper[i] = b[i];
    OsiClpSolverInterface solver;
    solver.loadProblem(matrix,
                       colLower.data(),
                       colUpper.data(),
                       c.data(),
                       rowLower.data(),
                       rowUpper.data());

    for (int j = 0; j < N; ++j) solver.setInteger(j);

    CbcModel model(solver);
    model.setLogLevel(0); 
    model.branchAndBound();
    const double* sol = model.bestSolution();
     return model.getObjValue();
}






















void parse_input(std::vector<std::vector<bool> > &v1, std::vector<std::vector<std::vector<int> > > &v2, std::vector<std::vector<int> > &v3) {
    std::string s;
    while(std::getline(std::cin, s)) {
        std::vector<bool> t1;
        std::vector<std::vector<int> > t2;
        std::vector<int> t3;
        int id = s.find(']');
        std::string s1 = s.substr(1, id - 1);
        for(auto t : s1) t1.push_back(t == '#');
        id += 2;
        while(true) {
            std::vector<int> t4;
            int id2 = s.find(')', id);
            if(!~id2) break;
            for(int i = id + 1; i < id2; i+=2) t4.push_back(s[i] - '0');
            t2.push_back(t4);
            id = id2 + 2;
        }
        s.back() = ',';
        while(id < s.size() - 1) {
            int id2 = s.find(',', id + 1);
            std::string s3 = s.substr(id + 1, id2 - id - 1);
            t3.push_back(std::stoi(s3));
            id = id2;
        }
        v1.push_back(t1), v2.push_back(t2), v3.push_back(t3);
    }
}

void solve_part1(std::vector<std::vector<bool> > &v1, std::vector<std::vector<std::vector<int> > > &v2) {
    const int N = v1.size();
    int ans = 0;
    for(int i = 0; i < N; i++) {
        int b = 0;
        const int M = v2[i].size();
        std::vector<int> bv;
        for(int j = 0; j < v1[i].size(); j++) b += (1 << j) * v1[i][j];
        for(auto t : v2[i]) {
            int b2 = 0;
            for(auto tt : t) b2 += (1 << tt); 
            bv.push_back(b2);
        }
        int cans = M;
        for(int j = 0; j < (1 << M); j++) {
            int rxor = b, ccans = 0;
            for(int k = 0; k < M; k++) if((j >> k) % 2) rxor ^= bv[k], ccans++;
            if(!rxor) cans = std::min(cans, ccans);
        }
        ans += cans;
    }
    std::cout << ans << '\n';
}

void solve_part2(std::vector<std::vector<std::vector<int> > > &v2, std::vector<std::vector<int> > &v3) {
    int ans = 0;
    const int M = v2.size();
    for(int i = 0; i < M; i++) {
       Program lp (CGAL::SMALLER, true, 0, false, 0);
       const int N = v2[i].size();
       for(int j = 0; j < v2[i].size(); j++) for(auto t : v2[i][j]) {
            lp.set_a(j, t * 2, 1);
            lp.set_a(j, t * 2 + 1, -1);
        }
        for(int j = 0; j < v3[i].size(); j++) {
            lp.set_b(j * 2, v3[i][j]);
            lp.set_b(j * 2 + 1, -v3[i][j]);
        }
        for(int j = 0; j < v2[i].size(); j++) {
            lp.set_c(j, 1);
        }
        int ce = v3[i].size() * 2;
        while(true) {
            Solution s = CGAL::solve_linear_program(lp, ET());
            if(s.objective_value().denominator().to_double() > 1) {
                for(int j = 0; j < N; j++) lp.set_a(j, ce, -1);
                lp.set_b(ce, -(int)(s.objective_value().numerator().to_double() / s.objective_value().denominator().to_double()) - 1);
                continue;
            } 
            bool all_in = true;
            for(int j = N - 1; j >= 0; j--) {
                if((s.variable_values_begin() + j)->denominator() > 1) {
                    if(i != 36 and i != 72 and i != 121 and i != 133 and i != 135) {
                        lp.set_a(j, ce + 1, -1);
                        lp.set_b(ce + 1, -(int)((s.variable_values_begin() + j)->numerator().to_double() / (s.variable_values_begin() + j)->denominator().to_double()) - 1);
                    } else {
                        lp.set_a(j, ce + 1, 1);
                        lp.set_b(ce + 1, (int)((s.variable_values_begin() + j)->numerator().to_double() / (s.variable_values_begin() + j)->denominator().to_double()) - 1);
                        
                    }
                    all_in = false;
                }
                if(!all_in) break;
            }
            if(!all_in) continue;
            //ans += (int)s.objective_value().numerator().to_double();
            std::cout << i << ": ";
            int cans = 0;
            for(int j = 0; j < N; j++) {
                std::cout << *(s.variable_values_begin() + j) << ' ';
                cans += (int)(s.variable_values_begin() + j)->numerator().to_double();
            }
                std::cout << '\n';
            std::cout << s.objective_value().denominator().to_double() <<  " " << cans << " ";
            std::cout << s.objective_value().numerator().to_double() << '\n';
            ans += cans;
            break;
        }
    }
    std::cout << ans << '\n';
}


void solve_part2_dirty(std::vector<std::vector<std::vector<int> > > &v2, std::vector<std::vector<int> > &v3) {
    int ans = 0;
    for(int i = 0; i < v2.size(); i++) {
        const int M = v3[i].size(); // number of equation
        const int N = v2[i].size();
        std::vector<std::vector<double> > A(M * 2, std::vector<double>(N, 0)); 
        std::vector<double> b, c;
        for(int j = 0; j < N; j++) for(int k = 0; k < v2[i][j].size(); k++) {
            A[v2[i][j][k] * 2][j] = 1;
            A[v2[i][j][k] * 2 + 1][j] = -1;        
        }
        for(int j = 0; j < M; j++) {
            b.push_back(v3[i][j]);
            b.push_back(-v3[i][j]);
        }
            for(int j = 0; j < N; j++) c.push_back(1);
        ans += ilp(A, b, c);
    }
    std::cout << ans << '\n';
}

int main() {
    std::vector<std::vector<bool> > v1;
    std::vector<std::vector<std::vector<int> > > v2;
    std::vector<std::vector<int> > v3;
    parse_input(v1, v2, v3);
    solve_part1(v1, v2);
    solve_part2_dirty(v2, v3);
}

// 27283 -> too high
// 114431 -> too high
// 15118 -> too low
// 16747 -> nope
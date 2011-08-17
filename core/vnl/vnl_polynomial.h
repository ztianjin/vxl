// This is core/vnl/vnl_polynomial.h
#ifndef vnl_polynomial_h_
#define vnl_polynomial_h_
#ifdef VCL_NEEDS_PRAGMA_INTERFACE
#pragma interface
#endif
//:
// \file
// \brief Evaluation of univariate polynomials
// Templated class (on the data type of the coefficients),
// further very similar to the vnl_real_polynomial class,
// except that it uses std::vector instead of vnl_vector as data container,
// and that the zero polynomial is represented by an empty vector.
//
// \author Peter Vanroose, ABIS Leuven.
// \date  August 2011

#include <vcl_vector.h>
#include <vcl_iosfwd.h>
#include <vcl_cassert.h>

//: Evaluation of polynomials.
//  vnl_polynomial<T> represents a univariate polynomial with
//  coefficients of datatype T, stored as a vector of values.
//  This allows evaluation of the polynomial $p(x)$ at given values of $x$,
//  and of its derivative $p'(x)$ or primitive function $\int p$.
//
//  The class also provides the common polynomial arithmetic, i.e.,
//  + - *, and even long division (through operators / and %).
//
//  The coefficients (coeffs_) are stored as a vector, starting with
//  the highest degree term. Hence coeffs_[n] is the coefficient of x^(d-n),
//  where d is the degree of the polynomial.

template <class T>
class vnl_polynomial
{
 public:
  //: Initialize polynomial.
  // The polynomial is $ a[0] x^d + a[1] x^{d-1} + \cdots + a[d] = 0 $.
  vnl_polynomial(vcl_vector<T> const& a): coeffs_(a) {}

  //: Initialize polynomial from C vector.
  // The parameter \p len is the number of coefficients,
  // which equals the degree plus one.
  vnl_polynomial(T const* a, unsigned len) { for (unsigned i=0;i<len;++i) coeffs_.push_back(a[i]); }

  //: Initialize polynomial from single value, thus creating a monomial.
  // Useful when adding or multiplying a polynomial with a number.
  vnl_polynomial(T const& a): coeffs_(1u, a) { if (a==T(0)) coeffs_.clear(); }

  //: Initialize polynomial of a given degree.
  // The default constructor initializes to the zero polynomial (which has degree -1).
  vnl_polynomial(int d=-1): coeffs_(d+1) { assert (d>=-1); }

  //: comparison operator
  bool operator==(vnl_polynomial<T> const& p) const { return p.coefficients() == coeffs_; }

  //: Returns negative of this polynomial
  vnl_polynomial<T> operator-() const;

  //: Returns polynomial which is sum of this with polynomial f
  vnl_polynomial<T> operator+(vnl_polynomial<T> const& f) const;

  //: Returns polynomial which is difference of this with polynomial f
  vnl_polynomial<T> operator-(vnl_polynomial<T> const& f) const { return operator+(-f); }

  //: Returns polynomial which is product of this with polynomial f
  vnl_polynomial<T> operator*(vnl_polynomial<T> const& f) const;

  //: Returns polynomial which is the result of the long division by polynomial f
  // Beware that this operation might not make sense for integral types T
  // if the highest order coefficient of f is not 1 or -1!
  vnl_polynomial<T> operator/(vnl_polynomial<T> const& f) const;

  //: Returns polynomial which is the remainder after a long division by polynomial f
  // Beware that this operation might not make sense for integral types T
  // if the highest order coefficient of f is not 1 or -1!
  vnl_polynomial<T> operator%(vnl_polynomial<T> const& f) const;

  vnl_polynomial<T>& operator+=(vnl_polynomial<T> const& f) { return *this = operator+(f); }
  vnl_polynomial<T>& operator-=(vnl_polynomial<T> const& f) { return *this = operator-(f); }
  vnl_polynomial<T>& operator*=(vnl_polynomial<T> const& f) { return *this = operator*(f); }
  vnl_polynomial<T>& operator/=(vnl_polynomial<T> const& f) { return *this = operator/(f); }
  vnl_polynomial<T>& operator%=(vnl_polynomial<T> const& f) { return *this = operator%(f); }

  //: Evaluate polynomial at value x
  T evaluate(T const& x) const;

  //: Return derivative of this polynomial
  vnl_polynomial<T> derivative() const;

  //: Evaluate derivative at value x
  T devaluate(T const& x) const { return derivative().evaluate(x); }

  //: Return primitive function (inverse derivative) of this polynomial
  // Since a primitive function is not unique, the one with constant term 0 is returned.
  // Beware that this operation might not make sense for integral types T!
  vnl_polynomial<T> primitive() const;

  //: Evaluate integral at x (assuming constant of integration is zero)
  // Beware that this operation might not make sense for integral types T!
  T evaluate_integral(T const& x) const { return primitive().evaluate(x); }

  //: Evaluate integral between x1 and x2
  // Beware that this operation might not make sense for integral types T!
  T evaluate_integral(T const& x1, T const& x2) const { return evaluate_integral(x2)-evaluate_integral(x1); }

  // Data Access---------------------------------------------------------------

  //: Return the degree (highest power of x) of the polynomial.
  // If the polynomial is zero, the degree is effectively -1.
  int     degree() const { return int(coeffs_.size()) - 1; }

  //: Access to the polynomial coefficients
  T& operator [] (int i)       { assert(i<=degree()); return coeffs_[i]; }
  //: Access to the polynomial coefficients
  T  operator [] (int i) const { assert(i<=degree()); return coeffs_[i]; }

  //: Return the vector of coefficients
  const vcl_vector<T>& coefficients() const { return coeffs_; }
  //: Return the vector of coefficients
        vcl_vector<T>& coefficients()       { return coeffs_; }

  void set_coefficients(vcl_vector<T> const& coeffs) {coeffs_ = coeffs;}

  //: Print this polynomial to stream
  void print(vcl_ostream& os) const;

 protected:
  //: The coefficients of the polynomial.
  // coeffs_.back() is the const term.
  // coeffs_[n] is the coefficient of the x^(d-n) term,
  //    where d=coeffs_.size()-1
  vcl_vector<T> coeffs_;
};

template <class T>
vcl_ostream& operator<<(vcl_ostream& os, vnl_polynomial<T> const& p) { p.print(os); return os; }

#define VNL_POLYNOMIAL_INSTANTIATE(T) extern "please #include vnl/vnl_polynomial.txx instead"

#endif // vnl_polynomial_h_

#include <list>
#include <stdexcept>

struct Coeff
{
	double		value;
	int			degree;
};


class Computor
{
// ** PRIVATE ** //
private:

	std::string			_str;
	std::string			_left;
	std::string			_right;
	std::list<Coeff>	_coeffs;
	int					_maxDegree;
	double				_a;
	double				_b;
	double				_c;

	Computor( const Computor & src );
	Computor &		operator=( const Computor & src );
	void			_initComputor( void );
	void			_replaceSubstract( void );
	void			_getLeftRight( void );
	void			_handle(std::string & part, int sign);
	void			_reducedForm( void );
	void			_printCoeffs( std::string info );
	void			_findSolutions( void );
	void			_findABC( void );
	void			_debugList();


// ** PUBLIC ** //

public:
	Computor( void );
	~Computor( void );

	void			treatEquation( std::string eq );


// ** EXCEPTIONS ** //

	class ComputorException : public std::runtime_error
	{
	private:
		ComputorException const & operator=(ComputorException const &) throw();
		ComputorException() throw();

	public:
		ComputorException(std::string const & errorMsg) throw();
		~ComputorException() throw();
		virtual const char* 		what() const throw();
	};

};

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	try
	{
		/* change grade to test other cases */
		Bureaucrat	b("bini", 40);
		Form		f("formi", 40, 36);

		std::cout << std::endl << "------sign formi--------" << std::endl;
		std::cout << f << std::endl;
		b.signForm(f);


		std::cout << std::endl << "------sign formi again--------" << std::endl;
		b.signForm(f);
		std::cout << f << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	return (0);
}

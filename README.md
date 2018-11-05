
Hello

-This is a package for monte carlo simulations of a 2D lattice with a U(1) gauge field defined on the links, obeying a Wilson gauge action.

-It uses the metropolis algorithm to generate an ensemble of gauge configurations.

-All parameters (Lattice size etc.) are set in 'main.h'.

-Typing 'make polyakov.exe' makes an executable which will calculate the expectation value of two polyakov loops on the lattice at varying separations. It estimates the variance of the average using a bootstrap analysis.

-Typing 'make metropolis_tuner.exe' makes an executable which generates an ensemble for many different values of 'epsilon' (range allowed for random phase angles added to a link during update), and displays the proportion of 'pass rates' of new configurations on each update. The ideal pass rate is 50%.


emclean Mar 2016
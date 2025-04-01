#include <fstream>
#include <iostream>
#include <iomanip>


using namespace std;


double mapsvalues (double x)     //funzione che mappa i valori da [1,5] a [-1,2]
{
	
	return -1 + ((x - 1) * 3) / 4;
}

int main()
{
	std::ifstream fstr ("data.txt"); 
	
	if (fstr.fail())  
	{   
        std::cerr << "file data not found" << std::endl; 
		return 1;
	}

	std::ofstream ofstr ("result.txt");
	
	ofstr << "# N Mean\n";
	
	if (ofstr.fail())  
	{   
        std::cerr << "file result not found" << std::endl; 
		return 1;
	}
	
    double val=0;
    unsigned int n=0;
    double mean=0; 
	double t=0;
	
   
   while (fstr >> val)
   {
	   t += mapsvalues(val);
	   n++;
	   
	   mean = t / n;  //media
	
	  
	  ofstr << std::setprecision(16) << std::scientific << n << " "<< mean << std::endl;
	  
   }
	
	fstr.close();
    
	ofstr.close();

    cout << "Results saved in result.txt" << endl;
   
	
    return 0;
}

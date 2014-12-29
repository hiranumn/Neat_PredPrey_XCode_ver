/*
 neatmain.cpp
 Runs the Predator/Prey experiment of the user's choosing.
*/
//#include <stdlib.h>
//#include <stdio.h>
//#include <iostream>
//#include <iomanip>
//#include <sstream>
//#include <list>
//#include <vector>
//#include <algorithm>
//#include <cmath>
//#include <iostream.h>
//#include "networks.h"
//#include "neat.h"
//#include "genetics.h"
//#include "experiments.h"
//#include "neatmain.h"
#include <iostream>
#include <vector>
#include "neat.h"
#include "population.h"
#include "experiments.h"
#include <time.h> 
using namespace std;

int main(int argc, char *argv[]) {

  NEAT::Population *p=0;


  if (argc < 3) {
	  cerr << "---------------------------------------" << endl;
    cerr << "USAGE: ./neat .nefile experiment# (generation file path)" << endl;
	  cerr << "Experiment numbers:" << endl; 
	  cerr<<"1 - Central Controller"<<endl;
	  cerr<<"2 - Communucating Predators"<<endl;
	  cerr<<"3 - Non-Communicating Predators"<<endl;
	  cerr<<"4 - Replay Previous Benchmark (requires SFML"<<endl;
	  cerr<<"5 - Replay with one predator (OLD, requires SFML)"<<endl;
	  cerr<<"6 - Conduct Super-benchmark"<<endl;
	  cerr << "---------------------------------------" << endl;
	  return -1;
  }
  
  int choice;

  choice = atoi(argv[2]);
	cout << "your choice is " << choice << "." << endl; 
  //Load in the params
  NEAT::load_neat_params(argv[1],false);
  cout<<"loaded"<<endl;
	cout<<NEAT::random_seed<<endl;
	srand(NEAT::random_seed);
  //Run the experiment
  switch ( choice ) {
    case 1:
      p = predprey_test_central(num_generations);
      break;
    case 2:
      p = predprey_test_comm(num_generations);
      break;
    case 3:
      p = predprey_test_nocomm(num_generations);
      break;
    case 4:
          // don't run visuals on linux; comment or change the macro to try anyway
#ifdef __linux__
          cerr << "Running on linux, so SFML probably isn't installed; exiting." << endl;
          cerr << "To disable this and try anyway, edit neatmain.cpp, line 69." << endl;
          return -1;
#endif
		  if (argc !=4){
			  cerr << "---------------------------------------" << endl;
			  cerr << "Need a generation file path!" << endl;
			  cerr << "USAGE: ./neat .nefile experiment# (generation file path)" << endl;
			  cerr << "---------------------------------------" << endl;
			  return -1;
		  }
      replay(argv[3]);
      break;
		case 5:
          // don't run visuals on linux; comment or change the macro to try anyway
#ifdef __linux__
          cerr << "Running on linux, so SFML probably isn't installed; exiting." << endl;
          cerr << "To disable this and try anyway, edit neatmain.cpp, line 85." << endl;
          return -1;
#endif
		  if (argc !=4){
			  cerr << "---------------------------------------" << endl;
			  cerr << "Need a generation file path!" << endl;
			  cerr << "USAGE: ./neat .nefile experiment# (generation file path)" << endl;
			  cerr << "---------------------------------------" << endl;
			  return -1;
		  }
			replayOnePred(argv[3]);
			break;
		case 6:
		  if (argc !=4){
			  cerr << "---------------------------------------" << endl;
			  cerr << "Need a generation file path!" << endl;
			  cerr << "USAGE: ./neat .nefile experiment# (generation file path)" << endl;
			  cerr << "---------------------------------------" << endl;
			  return -1;
		  }
			//re-seeding for randomizing starting location.
			srand(time(NULL));
			superbench(argv[3]);
			break;
    default:
      cout<<"Not an available option."<<endl;
  }

  if (p)
    delete p;

  return 0;
 
}


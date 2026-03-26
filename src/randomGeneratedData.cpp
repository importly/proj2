//https://www.datablist.com/learn/csv/download-sample-csv-files this is the website used to get the csv file for 100000 random names and emails
//used google to figure out topics in each department
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <random>
#include "randomGeneratedData.h"


void generate()
{
    std::vector<std::string> university = {"University of Florida", "Florida State University", "University of Miami", "University of South Florida", "University of Central Florida", "Florida International University", "Florida Atlantic University", "Florida Gulf Coast University", "NOVA Southeastern University", "University of North Florida"};
    std::vector<std::string> department = {"Computer Science", "Computer Engineering", "Mechanical Engineering", "Aerospace Engineering", "Electrical Engineering", "Biomedical Engineering", "Civil Engineering", "Chemical Engineering", "Nuclear Engineering", "Physics"};
    std::vector<std::string> CS = {"Machine Learning", "Distributed Vision", "Computer Vision", "Natural Language Processing", "Human-Computer Interaction"};
    std::vector<std::string> CPE = {"Embedded Systems Design", "Computer Architecture Optimization", "Autonomous Systems", "IoT security", "Microelectronics"};
    std::vector<std::string> ME = {"Fluid Dynamics", "Thermodynamics and Heat Transfer", "Additive Manufacturing", "Robotics and Mechatronics", "Vibrations and Control Systems"};
    std::vector<std::string> AE = {"Aerodynamics", "Propulsion Systems", "Flight Dynamics and Control", "Spacecraft Design", "Computational Fluid Dynamics"};
    std::vector<std::string> EE = {"Signal Processing", "Control Systems", "Microelectronics and VLSI Design", "Wireless Communications", "Power Systems and Smart Grids"};
    std::vector<std::string> BE = {"Medical Imaging", "Biomaterials Development", "Tissue Engineering", "Neural Engineering", "BioInstrumentation"};
    std::vector<std::string> CE = {"Structural Analysis", "Transportation Systems", "Geotechnical Engineering", "Environmental Engineering", "Construction Management"};
    std::vector<std::string> CHE = {"Process Design and Optimization", "Reaction Engineering", "Biochemical Engineering", "Polymer Science", "Separation Processes"};
    std::vector<std::string> NE = {"Reactor Design", "Radiation Detection and Measurement", "Nuclear Materials", "Nuclear Safety and Risk Analysis", "Fusion Energy"};
    std::vector<std::string> PHY = {"Quantum Mechanics", "AstroPhysics", "Particle Physics", "Condensed Matter Physics", "Optics and Photonics"};
    std::vector<std::string> level = {"Freshman", "Sophomore","Junior", "Senior"};

    std::vector<std::string> synopsis = {"This lab explores the application of ", "Focused on investigating methods to improve ", "Researching high performance applications in ", "Developing innovative approaches in ", "Analyzing challenges in "};

    std::ofstream outputFile("../src/researchData.csv");
    std::ifstream inputFile("../src/customers-100000.csv");
    std::string line;

    if (!outputFile.is_open()) {
        std::cout << "Failed to open researchData.csv for writing\n";
        return;
    }
    if (!inputFile.is_open()) {
        std::cout << "Failed to open customers-100000.csv\n";
        return;
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 9);

    std::random_device rd1;
    std::mt19937 gen1(rd1());
    std::uniform_int_distribution<> dist1(0, 3);

    int counter = 0;
    while (std::getline(inputFile, line)) {

        ++counter;
        std::stringstream ss(line);

        std::string temp;
        std::string firstName;
        std::string lastName;
        std::string email;

        //skips first two columns in csv
        std::getline(ss, temp, ',');
        std::getline(ss, temp, ',');

        std::getline(ss, firstName, ',');
        std::getline(ss, lastName, ',');
        email = firstName + lastName + "@gmail.com";
        //generate research info

        //generate random number between 1 and 10 to choose random college, etc.
        //learned how to do this from google
        int num = dist(gen);

        std::string uni = university[num];

        num = dist(gen);
        std::string dept = department[num];

        num = dist(gen);
        std::string topic;
        if (dept == "Computer Science") {
            topic = CS[num % 5];
        }
        else if (dept == "Computer Engineering") {
            topic = CPE[num % 5];
        }
        else if (dept == "Mechanical Engineering") {
            topic = ME[num % 5];
        }
        else if (dept == "Aerospace Engineering") {
            topic = AE[num % 5];
        }
        else if (dept == "Electrical Engineering") {
            topic = EE[num % 5];
        }
        else if (dept == "Biomedical Engineering") {
            topic = BE[num % 5];
        }
        else if (dept == "Civil Engineering") {
            topic = CE[num % 5];
        }
        else if (dept == "Chemical Engineering") {
            topic = CHE[num % 5];
        }
        else if (dept == "Nuclear Engineering") {
            topic = NE[num % 5];
        }
        else {
            topic = PHY[num % 5];
        }

        int num1 = dist1(gen1);
        std::string lev = level[num1];

        std::string labName = "Dr. " + lastName + "'s Lab";

        num = dist(gen);
        std::string synop = synopsis[num % 5] + topic + " in the field of " + dept + ".";

        outputFile << counter << ", " << uni << "," << dept << "," << topic << "," << lev << "," << labName << "," << firstName + " " + lastName + " " + email << "," << synop << std::endl;
        ss.clear();
        ss.str("");
    }

    outputFile.close();
    inputFile.close();
}

//https://www.datablist.com/learn/csv/download-sample-csv-files this is the website used to get the csv file for 100000 random names and emails
//used google to figure out topics in each department
#include <vector>
#include <iostream>
#include <string>

void generate()
{
    std::vector<std::string> university = {"University of Florida", "Florida State University", "University of Miami", "University of South Florida", "University of Central Florida", "Florida International University", "Florida Atlantic University", "Florida Gulf Coast University", "NOVA Southeastern University", "University of North Florida"};
    std::vector<std::string> department = {"Computer Science", "Computer Engineering", "Mechanical Engineering", "Aerospace Engineering", "Electrical Engineering", "Biomedical Engineering", "Civil Engineering", "Chemical Engineering", "Nuclear Engineering", "Physics"};
    std::vector<std::string> CS = {"Machine Learning", "Distributed Vision", "Computer Vision", "Natural Language Processing", "Human-Computer Interaction"};
    std::vector<std::string> CPE = {"Embedded Systems Design", "Computer Architecture Optimization", "Autonomous Systems", "IoT security"};
    std::vector<std::string> ME = {"Fluid Dynamics", "Thermodynamics and Heat Transfer", "Additive Manufacturing", "Robotics and Mechatronics", "Vibrations and Control Systems"};
    std::vector<std::string> AE = {"Aerodynamics", "Propulsion Systems", "Flight Dynamics and Control", "Spacecraft Design", "Computational Fluid Dynamics"};
    std::vector<std::string> EE = {"Signal Processing", "Control Systems", "Microelectronics and VLSI Design", "Wireless Communications", "Power Systems and Smart Grids"};
    std::vector<std::string> BE = {"Medical Imaging", "Biomaterials Development", "Tissue Engineering", "Neural Engineering", "BioInstrumentation"};
    std::vector<std::string> CE = {"Structural Analysis", "Transportation Systems", "Geotechnical Engineering", "Environmental Engineering", "Construction Management"};
    std::vector<std::string> CHE = {"Process Design and Optimization", "Reaction Engineering", "Biochemical Engineering", "Polymer Science", "Separation Processes"};
    std::vector<std::string> NE = {"Reactor Design", "Radiation Detection and Measurement", "Nuclear Materials", "Nuclear Safety and Risk Analysis", "Fusion Energy"};
    std::vector<std::string> PHY = {"Quantum Mechanics", "AstroPhysics", "Particle Physics", "Condensed Matter Physics", "Optics and Photonics"};
    std::vector<std::string> level = {"Freshman", "Sophomore","Junior", "Senior"};


    std::vector<std::string> synopsis = {"This lab explores the application of ", "Focused on investigating methods to improve ", "Researching high performance applications ", "Developing innovative approaches ", "Analyzing challenges in "};



}

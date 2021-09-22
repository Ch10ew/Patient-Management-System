// #include "NurseModule.h"
// #include "../Util/Util.h"

// #include <memory>
// #include <iostream>
// #include <cctype>

// namespace pms
// {
//     bool MatchAccount(std::shared_ptr<Nurse> n1, std::shared_ptr<Nurse> n2)
//     {
//         return (n1->username == n2->username) && (n1->password == n2->password);
//     }

//     // bool MatchPatientID(std::shared_ptr<Patient> p1, std::shared_ptr<Patient> p2)
//     // {
//     //     return p1->id == p2->id;
//     // }

//     // bool MatchPatientName(std::shared_ptr<Patient> p1, std::shared_ptr<Patient> p2)
//     // {
//     //     // use find
//     //     return (p1->first_name == p2->first_name) || (p1->last_name == p2->last_name);
//     // }

//     // bool MatchPatientAge(std::shared_ptr<Patient> p1, std::shared_ptr<Patient> p2)
//     // {
//     //     return p1->age == p2->age;
//     // }

//     // bool MatchPatientGender(std::shared_ptr<Patient> p1, std::shared_ptr<Patient> p2)
//     // {
//     //     return p1->gender == p2->gender;
//     // }

//     // bool MatchPatientContactNumber(std::shared_ptr<Patient> p1, std::shared_ptr<Patient> p2)
//     // {
//     //     return p1->contact_number == p2->contact_number;
//     // }

//     // bool MatchPatientAddress(std::shared_ptr<Patient> p1, std::shared_ptr<Patient> p2)
//     // {
//     //     // use find
//     //     return p1->address == p2->address;
//     // }

//     // bool MatchPatientDisability(std::shared_ptr<Patient> p1, std::shared_ptr<Patient> p2)
//     // {
//     //     return p1->disability == p2->disability;
//     // }

//     // bool MatchPatientVisit(std::shared_ptr<Patient> p1, std::shared_ptr<Patient> p2)
//     // {
//     //     return p1->disability == p2->disability;
//     // }
//     NurseModule::NurseModule(std::shared_ptr<ResourcePool> resource_pool)
//     : UI(resource_pool)
//     {
//         module_option_text_ = "Nurse Login";
//     }

//     void NurseModule::Run()
//     {
//         do
//         {
//             Login();
//             if (logged_in_)
//             {
//                 Menu();
//             }
//         }
//         while (!exit_);
//     }

//     void NurseModule::Login()
//     {
//         int option = -1;
//         bool show_invalid = false;
//         bool found = false;
//         bool exit = false;
//         std::string username, password;

//         do
//         {
//             std::cout << std::endl;
//             std::cout << std::endl;
//             if (show_invalid)
//             {
//                 std::cout << "\n" << "========== Invalid Credentials ==========" << std::endl;
//                 show_invalid = false;
//             }
//             else
//                 std::cout << "\n" << std::endl;
            
//             // Display options
//             std::cout << " = Nurse Login = " << std::endl;
//             std::cout << std::endl;
//             std::cout << "Username (\"!\" to exit): ";
//             std::cin >> username;

//             if (username == "!")
//             {
//                 exit_ = true;
//                 return;
//             }
            
//             std::cout << "Password: ";
//             std::cin >> password;

//             // Run selected option
//             int found = resource_pool_->nurse_data.Search(std::make_shared<Nurse>("", username, password, "", "", ""), MatchAccount);
//             if (found != -1)
//             {
//                 logged_in_nurse_ = resource_pool_->nurse_data.At(found);
//                 logged_in_ = true;
//                 exit = true;
//             }
//             else
//             {
//                 show_invalid = true;
//             }
//         }
//         while (!exit);
//     }

//     void NurseModule::Menu()
//     {
//         bool exit = false;

//         std::string* option_text = new std::string[7];
//         option_text[0] = "Add a new patient";
//         option_text[1] = "Modify patient record";
//         option_text[2] = "View patient list in descending order";
//         option_text[3] = "Call a patient";
//         option_text[4] = "Search for patient record";
//         option_text[5] = "Sort patient's list by waiting time";
//         option_text[6] = "Logout";

//         while (!exit)
//         {
//             int option = Util::Menu("Welcome, " + logged_in_nurse_->first_name, option_text, 4);

//             // Run selected option
//             std::cout << std::endl;
//             std::cout << std::endl;
//             switch (option)
//             {
//                 case 0:
//                     std::cout << " = Add a patient = " << std::endl;
//                     std::cout << std::endl;
//                     AddPatient();
//                     break;
//                 case 1:
//                     std::cout << " = Search & Modify = " << std::endl;
//                     std::cout << std::endl;
//                     //Modify(Search());
//                     break;
//                 case 2:
//                     std::cout << " = Pagination for patient = " << std::endl;
//                     std::cout << std::endl;
//                     //Pagination();
//                     break;
//                 case 3:
//                     std::cout << " = Search & View = " << std::endl;
//                     std::cout << std::endl;
//                     //PrintPatient(Search());
//                     break;
//                 case 4:
//                     std::cout << " = Search & View = " << std::endl;
//                     std::cout << std::endl;
//                     //PrintPatient(Search());
//                     break;
//                 case 5:
//                     std::cout << " = Search & View = " << std::endl;
//                     std::cout << std::endl;
//                     //PrintPatient(Search());
//                     break;
//                 case 6:
//                     std::cout << "Logging out..." << std::endl;
//                     logged_in_ = false;
//                     logged_in_nurse_ = nullptr;
//                     exit = true;
//                     break;
//             }
//         }

//         // free pointer above
//         delete[] option_text;
//     }

//     void NurseModule::AddPatient()
//     {
//         // std::string id;
//         // std::string first_name;
//         // std::string last_name;
//         // int age;
//         // char gender;
//         // std::string contact_number;
//         // std::string address;
//         // std::string disability;
//         // std::string tmp;
//         // bool invalid_input = false;

//         // std::string* input_text = new std::string[7];
//         // input_text[0] = "First Name: ";
//         // input_text[1] = "Last Name: ";
//         // input_text[2] = "Age: ";
//         // input_text[3] = "Gender(F/M): ";
//         // input_text[4] = "Contact Number: ";
//         // input_text[5] = "Address: ";
//         // input_text[6] = "Disability: ";

//         // for(int i = 0; i < 7; i++){
//         //     std::cout << std::endl;
//         //     std::cout << std::endl;
//         //     if (invalid_input)
//         //     {
//         //         std::cout << "\n" << "========== Invalid " + input_text[i] + " ==========" << std::endl;
//         //         invalid_input = false;
//         //     }
//         //         else
//         //             std::cout << "\n" << std::endl;
                    
//         //     std::cout << input_text[i];
//         //     switch (i)
//         //     {
//         //         case 0:
//         //             std::cin.ignore();
//         //             getline(std::cin, first_name);
//         //             break;
//         //         case 1:
//         //             std::cin.ignore();
//         //             getline(std::cin, last_name);
//         //             break;
//         //         case 2:
//         //             std::cin.ignore();
//         //             getline(std::cin, tmp);
//         //             try
//         //             {
//         //                 age = std::stoi(tmp);
//         //             }
//         //             catch(const std::exception& e)
//         //             {
//         //                 invalid_input = true;
//         //                 i--;
//         //             }
//         //             break;
//         //         case 3:
//         //             std::cin.ignore();
//         //             getline(std::cin, tmp);
//         //             gender = toupper(tmp[0]);
//         //             if(gender != 'F' || gender != 'M'){
//         //                 invalid_input = true;
//         //                 i--;
//         //             }
//         //             break;
//         //         case 4:
//         //             std::cin.ignore();
//         //             getline(std::cin, contact_number);
//         //             break;
//         //         case 5:
//         //             std::cin.ignore();
//         //             getline(std::cin, address);
//         //             break;
//         //         case 6:
//         //             std::cin.ignore();
//         //             getline(std::cin, disability);
//         //             break;
//         //     }
//         // }
//         // resource_pool_->patient_data.InsertTail(std::make_shared<Patient>(
//         //     "P00000002",
//         //     first_name,
//         //     last_name,
//         //     age,
//         //     gender,
//         //     contact_number,
//         //     address,
//         //     disability
//         // ));
//         // std::cout << std::endl;
//         // std::cout << std::endl;
//         // std::cout << "========== Patient Entered Successfully ==========" << std::endl;

//         // Patient copy = *(resource_pool_->patient_data.Tail());
//         // std::cout << copy.id << " - " << copy.first_name << " " << copy.last_name << std::endl;
//         // std::cout << "Age: " << copy.age << std::endl;
//         // std::cout << "Gender: " << copy.gender << std::endl;
//         // std::cout << "Contact Number: " << copy.contact_number << std::endl;
//         // std::cout << "Address: " << copy.address << std::endl;
//         // std::cout << "Disability: " << copy.disability << std::endl;
//         // std::cout << "Visit History: " << std::endl;
//         // std::cout << std::endl;


//     }
// } // namespace pms
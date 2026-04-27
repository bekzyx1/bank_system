#include <iostream>
#include <vector>



std::vector<int> acc_number_list = {};
std::vector<std::string> acc_name_list = {};
std::vector<std::string> acc_type_list = {};
std::vector<int> acc_balance_list = {};



class System {
public:
    float balance = 0;

    int acc_number = 0;
    float deposit_am = 0;
    float dep_amount = 0;
    float withd_amount = 0;
    bool acc_succes;
    float acc_hist;//null


    std::string name;
    std::string save_check;


public: //First step operation in bank making personal data
        //create Accaunt, for new person at enter bank
    void newAcc(std::string name, std::string save_check, float deposit_am) {

        this-> name = name;
        this-> save_check = save_check;
        this-> deposit_am = deposit_am;
        name.clear();
        acc_number = 0;
        //outputs
        std::cout << "---Create New Accaunt---" << std::endl;
        std::cout << "Account Number: "; std::cin >> acc_number; acc_number_list.push_back(acc_number); 
        std::cout << "Enter accaunt holder name: "; std::cin >> name; acc_name_list.push_back(name);
        std::cout << "Enter accaunt type (Saving/Checking): "; std::cin >> save_check; acc_type_list.push_back(save_check);
        std::cout << "Enter initial deposit amount: "; std::cin >> deposit_am; acc_balance_list.push_back(deposit_am);
        std::cout << "Account created successfully!" << std::endl;
        
    }



public: //Deposit is money which you add in own balance
    void depMoney(int acc_number, float dep_amount, float balance) {
        std::cout << balance << std::endl;

        std::cout << "---Deposit Money---" << std::endl;
        std::cout << "Enter account number: "; std::cin >> acc_number;
        for (int i = 0; i < acc_number_list.size(); i++) {
            if (acc_number == acc_number_list[i]) {
        
            std::cout << "Enter deposit amount: "; std::cin >> dep_amount;
            deposit_am += dep_amount; // that balance

            std::cout << "Succesfully deposited: " << dep_amount << std::endl;
            } else {
                std::cout << "account not found!" << std::endl;
            }
            break;
            std::cout << "depMoney: break not working!" << std::endl;
        }

        
        
    }


public:
    void WithdrawingMoney() {
        std::cout << "Enter accaunt number: "; std::cin >> acc_number;
        for (int i = 0; i < acc_number_list.size(); i++) {
            if (acc_number == acc_number_list[i]) {
                acc_succes = true;
                std::cout << "Enter withdrawal amount: "; std::cin >> withd_amount;
                deposit_am -= withd_amount;
                std::cout << "Successfuly withdrew " << withd_amount << " so'm" << std::endl;
                std::cout << "New balance: " << acc_balance_list[0] << " so'm" << std::endl;
                break;
            } else {
                std::cout << "accunt not founds!" << std::endl;
            }
            break;
            std::cout << "WithdrawingMoney: break not working!" << std::endl;
        }


    }  

public:
    void checkBalance() {
        std::cout << "Enter Accaunt number: "; std::cin >> acc_number;
        for (int i = 0; i < acc_number_list.size(); i++) {
            if (acc_number == acc_number_list[i]) {
                std::cout << "Current balance: " << acc_balance_list[0] << " so'm" << std::endl; 
            } else {
                std::cout << "accaount not found!" << std::endl;
            }
            break;
            std::cout << "checkBalance: break not working!" << std::endl;
        }
    }


public:
    void accDetails() {
        std::cout << "Account Number: " << acc_number << std::endl;
        std::cout << "Account Holder: " << name << std::endl;
        std::cout << "Account Type: " << save_check << std::endl;
        std::cout << "Current Balance: " <<  acc_balance_list[0] << std::endl;
    }


public:
    void allAccounts() {
        std::string dataName; 
        int dataNumber;
        int dataBalance;

        for (int i = 0; i < acc_number_list.size(); i++) {
            std::cout << acc_number_list[i] << std::endl;
            dataNumber += acc_number_list[i];
        }   

        for (int i = 0; i < acc_name_list.size(); i++) {
            std::cout << acc_name_list[i] << std::endl;
            dataName += acc_name_list[i];
        }

        for (int i = 0; i < acc_balance_list.size(); i++) {
            std::cout << acc_balance_list[i] << std::endl;
            dataBalance += acc_balance_list[i];
        }

        std::cout << "--- All Accounts ---" << std::endl;
        std::cout << "Account#   Name           Type     Balance" << std::endl;
        std::cout << dataNumber << "   " << dataName << "         " << save_check << "   " << dataBalance << std::endl;
    }


public:
    //this function showing all list of choice operation
    void showMenu() {
        std::cout << "--- Welcome to NitroBank ---" << std::endl;
        std::cout << "0.clicker giver money" << std::endl;
        std::cout << "1.Create Accaunt" << std::endl;
        std::cout << "2.Deposit Money" << std::endl;
        std::cout << "3.Withdraw Money" << std::endl;
        std::cout << "4.Check Balance" << std::endl;
        std::cout << "5.View Accaunt Details" << std::endl;
        std::cout << "6.List All Accaounts" << std::endl;
        std::cout << "7.Exit" << std::endl;
        std::cout << "Enter your choice (1-7): ";
    }

};


int main() {
    System bank;



    int choice;
    std::string Choice;
    std::string variant;
    bool variant_True = true;
    bool choice_t = true;

    bank.showMenu();
    std::cin >> choice;


 
    

    while (choice_t) {
        switch(choice) {
            case 0: std:: cout << "zeroans: Enter your choice (1-7): "; std::cin >> choice;
                break;
            case 1:
                bank.newAcc(bank.name, bank.save_check, bank.deposit_am);
                bank.showMenu();
                std::cin >> choice;
                break;
            case 2:
                bank.depMoney(bank.acc_number, bank.dep_amount, bank.balance);
                std::cout << "New balance: " << acc_balance_list[0] << " so'm" << std::endl;
                std::cout << " " << std::endl;
                std::cout << " " << std::endl;
                bank.showMenu();
                std::cin >> choice;
                break;
            case 3:
                bank.WithdrawingMoney();
                bank.showMenu();
                std::cin >> choice;
                break;
            case 4:
                bank.checkBalance();
                break;
            case 5:
                bank.accDetails();
            case 6:
                bank.allAccounts();
                break;
            case 7:
                std::cout << "Thank you for choosing us!" << std::endl;
                return 0;
            default:
                std::cout << "[error]-[ no this command! ] -> " << Choice << choice << "choice: "; std::cin >> choice;
                
                
                
        }
        
        std::cout << choice << std::endl;
        std::cout << "aaaaa" << std::endl;
    }





    return 0;
}
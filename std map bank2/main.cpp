#include <iostream>
#include <map>
#include <string>

class Bankomat {
private:
    std::map<std::string, double> konton;
    
public:
    std::string aktivtKonto;

    void skapaKonto() {
        std::string kontonummer;
        std::cout << "Ange önskat kontonummer: ";
        std::cin >> kontonummer;

        if (konton.find(kontonummer) != konton.end()) {
            std::cout << "Kontonummer finns redan. " << std::endl;
        } else {
            konton[kontonummer] = 0.0; 
            std::cout << "Konto med nummer " << kontonummer << " skapat! " << std::endl;
        }
    }

    void loggaIn() {
        std::string kontonummer;
        std::cout << "Ange ditt kontonummer: ";
        std::cin >> kontonummer;

        if (konton.find(kontonummer) != konton.end()) {
            aktivtKonto = kontonummer;
            std::cout << "Du är nu inloggad på konto " << kontonummer << ". " << std::endl;;
        } else {
            std::cout << "Kontonummer inte hittat." << std::endl;
        }
    }

    void taUtPengar() {
        if (aktivtKonto.empty()) {
            std::cout << "Inget konto är aktivt." << std::endl;
            return;
        }

        double belopp;
        std::cout << "Ange belopp att ta ut: ";
        std::cin >> belopp;

        if (belopp <= konton[aktivtKonto]) {
            konton[aktivtKonto] -= belopp;
            std::cout << belopp << " har tagits ut. Nytt saldo: " << konton[aktivtKonto] << std::endl;
        } else {
            std::cout << "Finns ej tillräckligt med pengar." << std::endl;
        }
    }

    void sattInPengar() {
        if (aktivtKonto.empty()) {
            std::cout << "Inget konto är aktivt. " << std::endl;
            return;
        }

        double belopp;
        std::cout << "Ange belopp att sätta in: ";
        std::cin >> belopp;

        konton[aktivtKonto] += belopp;
        std::cout << belopp << " har satts in. Nytt saldo: " << konton[aktivtKonto] << " " << std::endl;
    }

    void visaSaldo() {
        if (aktivtKonto.empty()) {
            std::cout << "Inget konto är aktivt. " << std::endl;
            return;
        }

        std::cout << "Ditt saldo är " << konton[aktivtKonto] << std::endl;
    }

    void loggaUt() {
        if (aktivtKonto.empty()) {
            std::cout << "Inget konto är aktivt. " << std::endl;
            return;
        }

        std::cout << "Du är nu utloggad från konto " << aktivtKonto << ". " << std::endl;
        aktivtKonto.clear();
    }
};





int main() {
    Bankomat bankomat;
    char val;

    do {
    std::cout << "\nHuvudmeny " << std::endl;
    std::cout << "1. Skapa konto " << std::endl;
    std::cout << "2. Logga in " << std::endl;
    std::cout << "3. Avsluta " << std::endl;
    std::cout << "Välj ett alternativ: ";
    std::cin >> val;

        switch (val) {
            case '1':
                bankomat.skapaKonto();
                break;
            case '2':
                bankomat.loggaIn();
                while (!bankomat.aktivtKonto.empty()) {
        std::cout << "\nKontomeny " << std::endl;
        std::cout << "1. Ta ut pengar " << std::endl;
        std::cout << "2. Sätt in pengar " << std::endl;
        std::cout << "3. Visa saldo " << std::endl;
        std::cout << "4. Logga ut " << std::endl;
        std::cout << "Välj ett alternativ: ";
        std::cin >> val;
                    switch (val) {
                        case '1':
                            bankomat.taUtPengar();
                            break;
                        case '2':
                            bankomat.sattInPengar();
                            break;
                        case '3':
                            bankomat.visaSaldo();
                            break;
                        case '4':
                            bankomat.loggaUt();
                            break;
                        default:
                            std::cout << "Ogiltigt val. " << std::endl;
                    }
                }
                break;
            case '3':
                std::cout << "Avslutar programmet... " << std::endl;
                break;
            default:
                std::cout << "Ogiltigt val, försök igen. " << std::endl;
        }
    } while (val != '3');

    return 0;
}

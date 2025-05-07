/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <rcosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:22:48 by rcosta-c          #+#    #+#             */
/*   Updated: 2025/05/07 12:22:49 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

void testObject(Base* obj, const std::string& description) {
    std::cout << "\n" << std::setfill('-') << std::setw(40) << "" << std::endl;
    std::cout << description << std::endl;
    
    std::cout << "*Test: ";
    identify(obj);
    
    if (obj) {
        std::cout << "&Test: ";
        identify(*obj);
    } else {
        std::cout << "&Test: Can't execute (*NULL)" << std::endl;
    }
}

int main() {
    // Inicializar o gerador de números pseudoaleatórios
    std::srand(static_cast<unsigned int>(std::time(NULL)));
    
    std::cout << std::setfill('=') << std::setw(50) << "" << std::endl;
    std::cout << "          ID TEST          " << std::endl;
    std::cout << std::setfill('=') << std::setw(50) << "" << std::endl;
    
    // Teste 1: Ponteiro nulo (NULL)
    Base* class1 = NULL;
    testObject(class1, "Test #1: *NULL");
    
    // Testes 2-4: Objetos gerados aleatoriamente
    Base* class2 = generate();
    testObject(class2, "Test #2: Random Object");
    
    Base* class3 = generate();
    testObject(class3, "Test #3: Random Object");
    
    Base* class4 = generate();
    testObject(class4, "Test #4: Random Object");
    
    // Testes com objetos específicos
    std::cout << "\n" << std::setfill('=') << std::setw(50) << "" << std::endl;
    std::cout << "          TEST A B C          " << std::endl;
    std::cout << std::setfill('=') << std::setw(50) << "" << std::endl;
    
    Base* objectA = new A();
    testObject(objectA, "Test: Object type A");
    
    Base* objectB = new B();
    testObject(objectB, "Test: Object type B");
    
    Base* objectC = new C();
    testObject(objectC, "Test: Object type C");
    
    delete class1;
    delete class2;
    delete class3;
    delete class4;
    delete objectA;
    delete objectB;
    delete objectC;

    return 0;
}
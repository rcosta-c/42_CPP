/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <rcosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 21:58:09 by rcosta-c          #+#    #+#             */
/*   Updated: 2025/05/05 21:58:52 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main()
{
    // Criar uma instância da classe Serializer
    Serializer serializer;

    // Criar um objeto Data
    Data* original = new Data;
    original->str = "Hello, serialization!";
    
    // Exibir o objeto original
    std::cout << "Original object:" << std::endl;
    std::cout << "Address: " << original << std::endl;
    std::cout << "Content: " << original->str << std::endl;
    
    // Serializar o objeto
    uintptr_t serialized = serializer.serialize(original);
    std::cout << "\nSerialized value (uintptr_t): " << serialized << std::endl;
    std::cout << "Serialized value (hex): 0x" << std::hex << serialized << std::dec << std::endl;
    
    // Desserializar o objeto
    Data* deserialized = serializer.deserialize(serialized);
    
    // Exibir o objeto desserializado
    std::cout << "\nDeserialized object:" << std::endl;
    std::cout << "Address: " << deserialized << std::endl;
    std::cout << "Content: " << deserialized->str << std::endl;
    
    // Verificar se os ponteiros são os mesmos
    std::cout << "\nVerificação:" << std::endl;
    if (original == deserialized)
        std::cout << "✅ Sucesso: Os endereços são idênticos!" << std::endl;
    else
        std::cout << "❌ Falha: Os endereços são diferentes!" << std::endl;
    
    // Modificar o objeto desserializado e verificar se o original também muda
    deserialized->str = "Modified after deserialization";
    std::cout << "\nApós modificar o objeto desserializado:" << std::endl;
    std::cout << "Original: " << original->str << std::endl;
    std::cout << "Deserialized: " << deserialized->str << std::endl;
    
    // Limpar memória
    delete original;
    
    return 0;
}
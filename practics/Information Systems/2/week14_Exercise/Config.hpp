#pragma once

#include "Memory.h"
#include "Processor.h"

#include <vector>

class Config {

    std::vector<const Component*> components;

public:

    void add(const Component& obj) {
        
        for(int i = 0; i < components.size(); ++i) {

            if (components[i]->operator==(obj)) return;
            
        }
        
        components.push_back(obj.clone());
    }


    void remove(const Component& obj) {
        
        for (std::vector<const Component*>::iterator it = this->components.begin(); it != components.end(); ++it) {

            if ((*it)->operator==(obj)) { 

                delete *it;
                this->components.erase(it);
            }
        }
    }

    void print() const {

        for (size_t i = 0; i < components.size(); i++)
        {
            components[i]->output(std::cout);
        }
        
    }
    
    ~Config() {

        for (size_t i = 0; i < this->components.size(); i++)
        {
            delete components[i];
        }
    }


};
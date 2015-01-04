/* 
 * File:   Element.h
 * Author: saucelabs
 *
 * Created on December 23, 2014, 2:43 PM
 */

#ifndef ELEMENT_H
#define	ELEMENT_H
#include "Entity.h"
#include <memory>
 #include <vector>

class Element: public SessionEntity {
public:
    using SessionEntity::SessionEntity;
   // Element();
    //Element(const Element& orig);
   // virtual ~Element();
    
    void click();
    void sendKey(int keynum);
    void sendKeys(const std::vector<int>&);
    void sendKeys(const std::string&);
    std::string text();
    std::string css(const std::string& property);
    std::string attribute(const std::string& attr);
    std::string name();

    Element clone_();
private:

};

#endif	/* ELEMENT_H */


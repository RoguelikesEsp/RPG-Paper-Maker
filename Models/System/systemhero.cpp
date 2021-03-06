/*
    RPG Paper Maker Copyright (C) 2017 Marie Laporte

    This file is part of RPG Paper Maker.

    RPG Paper Maker is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    RPG Paper Maker is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "systemhero.h"

// -------------------------------------------------------
//
//  CONSTRUCTOR / DESTRUCTOR / GET / SET
//
// -------------------------------------------------------

SystemHero::SystemHero() : SystemLang()
{

}

SystemHero::SystemHero(int i, LangsTranslation* names, int idClass) :
    SystemLang(i,names),
    m_idClass(idClass)
{

}

SystemHero::~SystemHero(){

}

int SystemHero::idClass() const { return m_idClass; }

// -------------------------------------------------------
//
//  INTERMEDIARY FUNCTIONS
//
// -------------------------------------------------------

void SystemHero::setCopy(const SystemHero& hero){
    SystemLang::setCopy(hero);
    m_idClass = hero.idClass();
}

// -------------------------------------------------------
//
//  READ / WRITE
//
// -------------------------------------------------------

void SystemHero::read(const QJsonObject &json){
    SystemLang::read(json);
    m_idClass = json["class"].toInt();
}

void SystemHero::write(QJsonObject &json) const{
    SystemLang::write(json);
    json["class"] = m_idClass;
}

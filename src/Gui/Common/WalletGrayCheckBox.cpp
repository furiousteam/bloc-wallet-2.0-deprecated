// Copyright (c) 2015-2017, The Bytecoin developers
//
// This file is part of Bytecoin.
//
// Intensecoin is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Intensecoin is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with Intensecoin.  If not, see <http://www.gnu.org/licenses/>.

#include "WalletGrayCheckBox.h"
#include "Settings/Settings.h"
#include "Style/Style.h"

namespace WalletGui {

const char GRAY_CHECK_STYLE_SHEET_TEMPLATE[] =
  "* {"
    "font-family: %fontFamily%;"
  "}"

  "WalletGui--WalletGrayCheckBox {"
    "color: %fontColorGray%;"
    "font-size: %fontSizeNormal%;"
    "background-color: #031b46;"
  "}"

  "WalletGui--WalletGrayCheckBox::indicator {"
    "width: 13px;"
    "height: 13px;"
  "}"

  "WalletGui--WalletGrayCheckBox::indicator:unchecked {"
    "border: 1px solid %borderColorDark%;"
  "}"

  "WalletGui--WalletGrayCheckBox::indicator:unchecked:hover {"
    "border: 1px solid %borderColorDark%;"
  "}"

  "WalletGui--WalletGrayCheckBox::indicator:unchecked:pressed {"
    "border: 1px solid %borderColorDark%;"
  "}"

  "WalletGui--WalletGrayCheckBox::indicator:checked {"
    "border: 1px solid %borderColorDark%;"
    "background-color: white;"
  "}"

  "WalletGui--WalletGrayCheckBox::indicator:checked:hover {"
    "border: 1px solid %borderColorDark%;"
    "background-color: white;"
  "}"

  "WalletGui--WalletGrayCheckBox::indicator:checked:pressed {"
    "border: 1px solid %borderColorDark%;"
    "background-color: white;"
  "}"

  "WalletGui--WalletGrayCheckBox::indicator:indeterminate:hover {"
    "border: 1px solid %borderColorDark%;"
  "}"

  "WalletGui--WalletGrayCheckBox::indicator:indeterminate:pressed {"
    "border: 1px solid %borderColorDark%;"
  "}";

WalletGrayCheckBox::WalletGrayCheckBox(QWidget *parent) : QCheckBox(parent) {
  setStyleSheet(Settings::instance().getCurrentStyle().makeStyleSheet(GRAY_CHECK_STYLE_SHEET_TEMPLATE));
}


WalletGrayCheckBox::~WalletGrayCheckBox() {
}

}

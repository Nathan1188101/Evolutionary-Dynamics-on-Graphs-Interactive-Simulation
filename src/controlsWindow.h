#pragma once
#include<SFML/Graphics.hpp>
#include<TGUI/TGUI.hpp> // ui 
#include<TGUI/Backend/SFML-Graphics.hpp>

class controlsWindow {
    public:
        ControlsWindow(tgui::Gui& gui, float x, float y, float width, float height);
        void toggle(); 
        void setVisible(bool visible);
        void

    private: 
        // make the things that make up the window private, shouldn't be edited else where
        tgui::ChildWindow::Ptr controlsWindowContainer;
        tgui::Panel::Ptr panel
        


}
#include "controlsWindow.h"

ControlsWindow::ControlsWindow(tgui::Gui& gui, float x, float y, float width, float height) {
    // create the main child window container
    controlsWindowContainer = tgui::ChildWindow::create();
    controlsWindowContainer->setPosition(x, y);
    controlsWindowContainer->setSize(width, height);
    controlsWindowContainer->setTitle("Controls");
    
    // create a panel inside the child window for controls
    panel = tgui::Panel::create();
    panel->setSize(width - 20, height - 50);
    panel->setPosition(10, 10);
    
    // style the panel
    auto panelRenderer = panel->getSharedRenderer();
    panelRenderer->setBackgroundColor(tgui::Color(40, 40, 40));  // dark background
    
    // labels for keybinds stored as pairs
    std::vector<std::pair<std::string, std::string>> controls = {
        {"E", "Place Node"},
        {"C", "Set Cooperator"},
        {"F", "Set Defector"},
        {"G", "Place Grid"},
        {"Space", "Play/Pause Simulation"},
        {"Backspace", "Delete All"},
        {"A/D", "Move Left/Right"},
        {"W/S", "Move Up/Down"},
        {"Scroll", "Zoom In/Out"},
        {"Right Click + Drag", "Connect Edges"},
    };

    // loop through and set the pos of each label y offest of 10 each time from the last
    float yOffset = 10;
    for (const auto& control : controls) {
        auto label = tgui::Label::create();
        label->setText(control.first + " - " + control.second);
        label->setTextSize(12);
        label->setPosition(10, yOffset);
        
        // style the label with white text
        auto labelRenderer = label->getSharedRenderer();
        labelRenderer->setTextColor(tgui::Color::White);
        
        panel->add(label);
        yOffset += 25;
    }
    
    controlsWindowContainer->add(panel);
    gui.add(controlsWindowContainer);
    
    // start hidden
    controlsWindowContainer->setVisible(false);
}

void ControlsWindow::toggle() {
    controlsWindowContainer->setVisible(!controlsWindowContainer->isVisible());
}

void ControlsWindow::setVisible(bool visible) {
    controlsWindowContainer->setVisible(visible);
}

bool ControlsWindow::isVisible() const {
    return controlsWindowContainer->isVisible();
}
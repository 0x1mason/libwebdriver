// Copyright 2015 Eric Millin
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.


#ifndef ACTION_H
#define ACTION_H

#include <vector>


// example
//
//  auto session = Session::create("localhost:4723", caps);
//  auto win = session.currentWindow();
//  win.touch().down().move(x, y + 50).up().whilst()
//             .down().move(x, y - 50).up()
//             .perform();
class Action;
typedef std::vector<Action> Actions;

class Action
{
public:
    void perform(); // send _actions
    
protected:
    std::vector<Actions> _parallelActions;
    Actions _actionSeries;
};


class MouseAction: public Action
{
public:
    MouseAction& down() { return *this; };
    MouseAction& up() { return *this; };
    MouseAction& move() { return *this; };
    MouseAction& dblClick() { return *this; };
    MouseAction& click() { return *this; };
};


class TouchAction: public Action
{
public:
    TouchAction& whilst() { return *this; };
    TouchAction& down() { return *this; };
    TouchAction& up() { return *this; };
    TouchAction& move() { return *this; };
    TouchAction& dblClick() { return *this; };
    TouchAction& click() { return *this; };
};


#endif // ACTION_H

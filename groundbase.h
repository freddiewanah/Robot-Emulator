/*
 * Copyright (C) Kreogist Dev Team
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#ifndef GROUNDBASE_H
#define GROUNDBASE_H

#include <QList>

#include <QWidget>

class Robot;
class MenuBar;
class GenerateGroundBase;
/*!
 * \brief This is the abstraction class of the ground. It contains all the
 * interfaces which a ground class should be realized.\n
 * A Ground class is the widget which is going to show up the robots,
 * borders and barracks. It has to detected all the robots and set the
 * information to all the robots. The Ground class should contains all the
 * environmental information.
 */
class GroundBase : public QWidget
{
    Q_OBJECT
public:
    /*!
     * \brief Construct Ground class with the given parent.
     * \param parent The parent widget of the Ground class.
     */
    GroundBase(QWidget *parent = 0):QWidget(parent){}

    /*!
     * \brief The outside border which all the robots is going to guard.
     * \return The border QPolygonF class of the border.
     */
    virtual QPolygonF border() const=0;

    /*!
     * \brief Get the color of the border.
     * \return The QColor of the border.
     */
    virtual QColor borderColor() const=0;

    /*!
     * \brief The barracks border which all the robots is going to be set at
     * beginning.
     * \return The border QPolygonF class of the barracks.
     */
    virtual QPolygonF barracks() const=0;

    /*!
     * \brief Get the color of the barracks border.
     * \return The QColor of the barracks border.
     */
    virtual QColor barracksColor() const=0;

    /*!
     * \brief Add a robot to the ground. It will detect the start position of
     * the robot. If the robot is out side the barracks, will delete the robot.
     * \param robot The robot class which is going to be added.
     * \return If add the robot sucessfully, return true, or else return false.
     */
    virtual bool addRobot(Robot *robot)=0;

    /*!
     * \brief Add a lots of robots to the ground. It will call addRobot()
     * function for several times.
     * \param robots
     */
    virtual void addRobots(const QList<Robot *> &robots)=0;

    /*!
     * \brief Set the menu bar to add control actions.
     * \param menuBar The menu bar.
     */
    virtual void setMenuBar(MenuBar *menuBar)=0;

    /*!
     * \brief Set a ground generator.
     * \param generator The ground generator.
     */
    virtual void setGenerator(GenerateGroundBase *generator)=0;

signals:
    /*!
     * \brief When the user change the border, this signal will be emitted.
     */
    void borderChanged();

    /*!
     * \brief When the user change the barracks border, this signal will be
     * emitted.
     */
    void barracksChanged();

public slots:
    /*!
     * \brief Sets the border for the ground to border. \n
     * The border must be at least a triangle, if it's not a more complex
     * polygon than a triangle, the border will not be set.\n
     * When the new border has been set, the barracks will be reset to empty.
     * \param border The target border QPolygonF.
     */
    virtual void setBorder(const QPolygonF &border)=0;

    /*!
     * \brief Sets the border for the barracks of robots.\n
     * If there's any point which is not in the sets border, this barracks will
     * not be set.
     * \param barracks The target barracks QPolygonF.
     */
    virtual void setBarracks(const QPolygonF &barracks)=0;

    /*!
     * \brief Sets the color of the border.
     * \param borderColor The prefer color of the border.
     */
    virtual void setBorderColor(const QColor &borderColor)=0;

    /*!
     * \brief Pause the main time line.
     */
    virtual void pause()=0;

    /*!
     * \brief Continue running the main time line.
     */
    virtual void start()=0;

    /*!
     * \brief Reset all the robot at the start position.\n
     * All the robot's guardian line will be removed, and the position and
     * direction will be also reset.
     */
    virtual void reset()=0;

    /*!
     * \brief Ask all the robot move only once.\n
     * Notice that this function only available when the main time line is
     * paused.
     */
    virtual void nextFrame()=0;
};

#endif // GROUNDBASE_H

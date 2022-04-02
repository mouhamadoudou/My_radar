# My_radar

Description

my_radar is an air traffic graphical simulation. Planes fly from a control tower to another, and reset when they reach their destination or collide with one another. Two planes colliding within a tower control area are not destroyed and can continue on their way.

I used an AABB (Axis Aligned Bounding Box) algorithm for collision detection and a quadtree spatial partitionning to reduce the number of checks per plane.

The root version of this project is used for my Epitech delivery and contains no banned functions. Please use the version located in the bonus directory if you wish to use all features, which includes :

    a start menu
    displaying the quadtree
    a day and night cycle
    pausing the simulation

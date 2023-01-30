# Decorator design pattern

The Decorator design pattern is a structural pattern that allows behavior to be added to an individual object, either statically or dynamically, without affecting the behavior of other objects from the same class. The decorator pattern is often useful for adhering to the Single Responsibility Principle, as it allows behavior to be divided between classes with unique areas of concern.

It is implemented by creating a decorator abstract class that implements the interface of the component it decorates. The decorator class is then able to add new behavior before or after delegating a call to the component.

The Decorator pattern is a flexible alternative to sub-classing for extending functionality.

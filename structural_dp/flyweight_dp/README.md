# Flyweight Deesign Pattern

The Flyweight pattern is a structural design pattern that allows an application to efficiently use a large number of similar objects. The pattern reduces the number of objects created by sharing objects that are identical or similar.

In the Flyweight pattern, an object is divided into two parts: the intrinsic state and the extrinsic state. The intrinsic state is the data that is stored within the flyweight object and is shared among multiple clients. The extrinsic state is the data that is stored outside the flyweight object and is specific to each client.

The flyweight pattern is particularly useful when an application needs to create a large number of objects that are similar in some way. By sharing the intrinsic state among multiple objects, the Flyweight pattern can significantly reduce the amount of memory and processing required.

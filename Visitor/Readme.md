# Visitor
Add similar functionality to many different classes and the functionality doesn't make sense inside the class itself.

Don't add logic to each of the classes, separate it into a specific class or classes.

```mermaid
classDiagram

class VisitorInterface
class WriteToDatabaseVisitor
class ExportToFileVisitor
class ExportToJSONVisitor

VisitorInterface    :   execute(A a)
VisitorInterface    :   execute(B b)
VisitorInterface    :   execute(C c)

WriteToDatabaseVisitor    :   execute(A a)
WriteToDatabaseVisitor    :   execute(B b)
WriteToDatabaseVisitor    :   execute(C c)

ExportToFileVisitor    :   execute(A a)
ExportToFileVisitor    :   execute(B b)
ExportToFileVisitor    :   execute(C c)

ExportToJSONVisitor    :   execute(A a)
ExportToJSONVisitor    :   execute(B b)
ExportToJSONVisitor    :   execute(C c)

VisitorInterface <|-- WriteToDatabaseVisitor
VisitorInterface <|-- ExportToFileVisitor
VisitorInterface <|-- ExportToJSONVisitor

class A
A: accept(Visitor v)
class B
B: accept(Visitor v)
class C
C: accept(Visitor v)
```
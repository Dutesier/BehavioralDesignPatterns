# Null-Object
Define default behaviour of an object so that other objects can interact with it without worrying about its existence.

```mermaid
classDiagram

class LoggerInterface
class ConsoleLogger
class FileLogger
class APILogger

LoggerInterface :   write(info)
ConsoleLogger :   write(info)
FileLogger :   write(info)
APILogger :   write(info)

LoggerInterface <|.. ConsoleLogger
LoggerInterface <|.. FileLogger
LoggerInterface <|.. APILogger
```

What if no instance of logger has been created?

Define a *null object* that does nothing but provide a safe interface for other objects to interact with.
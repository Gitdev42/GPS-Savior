# GPS-Saviour
**GPS-Saviour** will be a Software to run on an GPS-GSM-module to locate lost stuff.

The GPS-Saviour project consist out of two main parts:
1. Encrypted communication between the NeedyClient and the SaviourClient
2. Logging the GPS-coordinates after activation.

The clients communicate via SMS. To make sure you are the only one who can activate the GPS-tracker the clients use a SSH inspired authentication.


## Testing
The GPS-Saviour project is tested with the C++ header-only unit-testing framework [**catch**](https://github.com/philsquared/Catch).

The test-documentation will be found within the [**docs**](https://github.com/Gitdev42/GPS-Saviour/tree/master/GPS-Saviour/docs) folder.
The test-code can be found within the [**test**](https://github.com/Gitdev42/GPS-Saviour/tree/master/GPS-Saviour/test) folder.

## Programming style
== !Attention! Please note that this project is developed as a C++ - beginner - project. Therefore the design, syntax and the programming style might not be perfect. ==

The code of this project is based on a styleguide which can be found within the [**docs**](https://github.com/Gitdev42/GPS-Saviour/tree/master/GPS-Saviour/docs) folder.


This project combines C++ with Python to read files from disk, then write the contents to the screen.

This project was quite difficult at first. I at first struggled to combine the languages, but over time it became rather straight forward to do.

The projects overall goal is to count words. It gathers a word count from a file, and outputs those counts to a data file. Finally, it will output to screen the count of each word. 

I particularly like the way that Python can create a histogram on screen. However, in the final product, the histogram is in fact created by C++. I think that the way I've structured the app is a little finicky, but I also the way I jump between Python and C++ so seamlessly.

I found it most challenging to create the multiple parameter functions. To overcome this hurdle, I read online forums, and documentation on how the linking between C++ and Python works. I also read the existing functions over and over again until I fully understood them.

I believe that the skill that will be most transferable that I learned within this project will be the integration and debug process I had to adapt to. It's very difficult to debug two languages at once, and thus I had to develop a system of doing so. I would start with C++ and follow the code through its execution, reading it step by step, then I would move to Python and repeat.

My biggest contribution to making this project readable and maintainable was carrying the Python naming conventions over from standard Python. The provided code seemingly had no convention, and thus would be likely to cause errors when being called from the C++ side of things. Nothing hurts good code quite like inconsistency. I also spent a little extra time here and there adding in extra comments, and summaries to functions to ensure a follow-up developer would be capable of maintaining the app.

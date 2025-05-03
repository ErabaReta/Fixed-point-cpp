# Fixed-point-cpp
implementing Fixed point class to replace floating points in c++
## THE IDEA
As we all know (or most of us) floating point was  a smart invention but it unfortunatly the add a computing overhead. well, yeah they sucks, so I m trying today to make a simple design for a Fixed point where we prefer computing speed over precision, accurracy, range, overflow risk, whoah thats many things. but yeah we get more perfermonce , yay!

What? the speed will be noticable only on micro contoller since modern hardware accelerates floating points arithmetic thanks to FPU? and using them could make things worst? yeh, but still the floats are bad, they kittins, the root of all, abd they theoricly consume more energy compared to integers arithmetics, and usefull on old hardware where could be lack for float SIMD, and there is integer one instead.


(i ll put later why floating points are bad, and why we call them floats, and why  fixed called fixed, or may be you do a pull request and do it ? add some feature or something too, I m lazy).

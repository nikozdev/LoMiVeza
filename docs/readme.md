# LoMiVeza
- Language Of My Vesania
> as verbose as i wanted
## crazy rules
- same-scope-same-length naming
> makes it easier to edit and go through
- more general words are in front
> make changes by changing the tail, not the head
- as less operator/sign/keyword intersection as possible
> we do not want multiple meanings of the same word
- one expression - one line
- spaces do not matter anywhere
> because all names and literals are separated from each other by signs
```
statical@Number#Number{1} == statical @Number #Number { 1 }
```
- Names can repeat, only keywords are unique
> but keywords are not reserving variable or function or type names
> > because they are written without any special signs
- A variable or a type can have multiple names in one declaration
## example
```
[[
deliberately complicated example
> optimized for demonstration rather than readability
]]

[=[
multiline comment of level 1 begins
[[
multiline comment of level 0 begins and closes
]]
multiline comment of level 1 closes
]=]

[[
statical type
> can only be defined at compile-time, without runtime fields and closures
> cannot be changed anymore
]]
statical #StringOfGreeting? {

    constant @Hello? #StringOfC { "hello" } @Hello!
    statical @World? #StringOfCpp { "world" } @World!
    variable @Space? #SymbolOfAscii { ' ' } @Space!

    constant $Print? {
        @Standard $Print( @self@Hello, @self@Space, @self@World, ) ()
    } $Print!

} #StringOfGreeting!

constant $Print? (@StringOfGreeting?#StringOfGreeting,) {
    @StringOfGreeting$Print()()
} $Print!

statical $PrintGreeting? ()(@String?#String,) {
    statical @StringOfGreeting #StringOfGreeting
    $Print(@StringOfGreeting)
    @String(@StringOfGreeting)
} $PrintGreeting!

constant$Main? {
    @PrintedString?#StringOfCpp
    $PrintGreeting()(@PrintedString,)
    @ArrayOfSint#Uint(10)
    @ArrayOfSint#Sint(10)
} $Main!

$Main

```
## modifier of const
- variable for names having mutable value
- statical for evaluating an expression, or making a constant at compile-time
- constant for names having immutable value
> constant types can be defined during the execution
## sign
- any arithmetics: +,-,*,/,%,(,),
- bin arithmetics: ~,|,&,^,<<,>>,
- logic: <|,<=,>=,>|,==,
- . to call a func
> , to separate the call arguments
- ? after name to begin definition of anything
- ! after name to close definition of anything with a scope
- \$ sign for func name
- \# sign for type name
- \@ sign for data name
- { scope }

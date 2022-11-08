
# Lyra Actor with Abilities (and Health)

THIS CODE WILL NOT COMPILE.

For a detailed overview of this code and why it's here, see my blog:
[x157 Dev Notes: UE5 Lyra Health and Damage](https://x157.github.io/UE5/LyraStarterGame/Health-and-Damage/)

I copied some of my `XCL` classes to this repo purely to show **an example** of how this works.
This is not intended to be cut/paste code that solves your problem for you.
Instead, it is intended to be an example you can read in order to create your own classes.

This references `XCL_ALOG` and other logging macros that exist in my `XCL` project that you will
not have access to.  Modify these to be your own logging macros as appropriate.

This also references `UXCLAbilitySystemComponent` which you will not have.  You should instead
use `ULyraAbilitySystemComponent`, upon which my XCL ASC is based.

The added functionality of `XCL` ASC is not required, but the `Lyra` ASC is definitely required,
as we are calling Lyra stuff in this code.  (In particular, the `HealthComponent` requires
access to a `Lyra` ASC).


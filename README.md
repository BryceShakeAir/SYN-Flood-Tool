<h2>Introduction</h2>
I have created a syn flood tool which successfully performs a dos attack on a virtual machine.
While doing so I have made my own protocol using the help of boost asio framework .All
program are made in cpp.To help you get started up on boost asio , I have attached a readme file
too.
<h2>Components</h2>
<ol>
<li>Main file</li>
<li>Protocol header file</li>
<li>Tcp header file</li>
<li>Ip header file</li>
<li>Iphdrincl file</li>
<li>Raw tcp header file</li>
</ol>

<h2>Environment used for Demo</h2>

I have demonstrated the attack using virtual box .Two machines, with ubuntu being the attacker
and windows xp being the victim. I have also set up a virtual switch so all connections are made
within the network i.e there are no connections to the internet. Utmost care has been taken while
using the tool since it is a legal offence .
Software Architecture
Boost.Asio is a cross-platform C++ library for network and low-level I/O programming that
provides developers with a consistent asynchronous model using a modern C++ approach.It
provides the functionality to make your own protocol.All protocols are designed in an object
oriented fashion.This is why such a functionality has been possible.

<h2>Sources</h2>
<ul>
<li>Boost.Asio C++ Network Programming Cookbook
Book by Dmytro Radchuk </li>
<li>Linux Man Pages </li>
<li>Boost Asio man pages </li>
</ul>
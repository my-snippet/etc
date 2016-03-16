from callbacks import *

d = Deferred()
d.addCallback(callback1)
d.addCallback(callback2)
d.callback("Test")
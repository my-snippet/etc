from callbacks import *


d = Deferred()
d.addErrback(errback1)
d.errback(0)
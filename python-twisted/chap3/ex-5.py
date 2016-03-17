from callbacks import *


d = Deferred()
d.addErrback(errback1)
d.addErrback(errback3)
d.errback(0)
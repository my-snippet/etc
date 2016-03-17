from callbacks import *


d = Deferred()
d.addErrback(errback2)
d.errback(0)

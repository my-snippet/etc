from datetime import datetime
from twisted.web.util import redirectTo


def _render_GET(self, request):
    return redirectTo(datetime.now().year, request)
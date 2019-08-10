USE `pastebin`;
DELETE FROM links WHERE expire <= NOW();

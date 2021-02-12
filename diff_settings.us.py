#!/usr/bin/env python3
BASENAME = 'sssv'
VERSION = 'us'

def apply(config, args):
    config['baseimg'] = f'baserom.{VERSION}.z64'
    config['myimg'] = f'build/{BASENAME}.{VERSION}.z64'
    config['mapfile'] = f'build/{BASENAME}.{VERSION}.map'
    config['source_directories'] = ['src', 'src.us', 'include']

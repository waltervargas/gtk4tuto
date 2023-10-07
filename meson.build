project(
  'gtktutorial',
  'c',
  default_options: ['warning_level=1']
)

gtk = dependency('gtk4')

executable(
    'justwindow',
    'justwindow.c',
    dependencies: [gtk]
)

executable(
    'widgets',
    'widgets.c',
    dependencies: [gtk]
)
